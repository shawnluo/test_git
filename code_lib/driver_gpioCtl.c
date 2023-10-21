
/*
Linux用户态控制GPIO--基于友善mini2440
在用户态控制GPIO的程序，省去了写驱动的麻烦，减少了系统调用，
直接将GPIO块的寄存器映射到用户空间，直接控制寄存器，提高了效率
本程序可直接用对应的cross compiler进行编译：
arm-linux-gcc -o gpio_ctrl gpio_ctrl.c
*/

/*
 * gpio_ctrl.c: user mode software to control the GPIO of S3C2440
 * Author Youri Zhang 2010-12-28 (yahui9635@gmail.com)
 * Reach the Author first before release this program.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#undef PAGE_SIZE
#undef PAGE_MASK

#define APP_NAME "gpio_ctrl"
#define VERSION	 "1.0"
#define BUILD_DATE __DATE__

#define PAGE_SHIFT		12
#define PAGE_SIZE  		(1<<PAGE_SHIFT)		/* 4096byte Per Mapped Memory page */
#define PAGE_MASK 		(~(PAGE_SIZE-1) )

#define GPIO_EndAddr	0x560000DC
#define GPIO_StartAddr	0x56000000

#define CLKREG_StartAddr	0x4C000000 
#define CLKREG_EndAddr	0x4C000018 
#define CLKCON 		0x0C

#define REG(Addr)	(*(volatile unsigned int*) (Addr))

static char* GPIOConStatus[4] = {"INPUT", "OUTPUT", "SpecialUse", "Reserved"};
static char* GPIODataStatus[2] = {"LOW", "HIGH"};
static char* GPIOPullupStatus[2] = {"Enabled", "Disabled"};

static void print_usage(void)
{
	fprintf(stdout,"************Help information for %s*************\n",APP_NAME);
	fprintf(stdout,"[Usage] %s -[b:n:c:w:p:rsdh] <value>\n", APP_NAME);
	fprintf(stdout,"Version: %s, Date: %s, Author: Youri Zhang\n\n", VERSION, BUILD_DATE);
	fprintf(stdout,"\t-b : (Must use 1st)specify the GPIO Bank index\n\t\t==>GPA's index is 0, GPB's index is 1 ... GPH's index is 7, GPJ's index is 8\n");
	fprintf(stdout,"\t-n : (Must use 2nd)specify the GPIO num in GPIO Bank\n");
	fprintf(stdout,"\t-c : Config the GPIO type(GPA use)\n\t\t==>OUTPUT:'-c 0x00', Special use:'-c 0x01'\n");
	fprintf(stdout,"\t-c : Config the GPIO type(GPB--J use)\n\t\t==>INPUT:'-c 0x00', OUTPUT:'-c 0x01', Special use:'-c 0x02', Reserved:'-c 0x03'\n");
	fprintf(stdout,"\t-w : Write value to GPIO pin's Data_reg\n");
	fprintf(stdout,"\t-p : Config value to GPIO pin's Pullup_reg\n\t\t==>Enable:'-p 0x00', Disable:'-p 0x01'\n");
	fprintf(stdout,"\t-r : Read the GPIO pin Data_reg's value\n");
	fprintf(stdout,"\t-s : Show the GPIO pin Config_reg's value\n");
	fprintf(stdout,"\t-d : Display the GPIO pin Pullup_reg's value\n");
	fprintf(stdout,"\t-h : This help information\n\n");
	fprintf(stdout,"Ex:\tConfig GPG4 output & write 0 to GPG4 Data_reg&enable pullup&read Data_reg&show configure&show pullup\n\t\t==> (%s -b 6 -n 4 -c 1 -w 0 -p 0 -s -r -d)\n", APP_NAME);
	fprintf(stdout,"\t\t==> (%s -b 0x06 -n 0x04 -c 0x01 -w 0x00 -p 0x00 -s -r -d)\n\t\t--> both decimal and hexadecimal input are ok!\n", APP_NAME);
	fprintf(stdout,"Ex:\tConfig the GPA4 output and write 0 to GPG4 Data_reg\n\t\t==> (%s -b 0 -n 4 -c 0x00 -w 0)\n", APP_NAME);
	fprintf(stdout,"Ex:\tConfig the GPG4 output and read GPG4 Data_reg's value\n\t\t==> (%s -b 6 -n 4 -c 0x01 -r)\n", APP_NAME);
	fprintf(stdout,"Ex:\tConfig the GPG4 output and show GPG4 Config_reg's value\n\t\t==> (%s -b 6 -n 4 -c 0x01 -s)\n", APP_NAME);
}

/* enable PCLK(50Mhz) to GPIO Block */
static void s3c2440_clkcon_init(void*  REG_CLK)
{
	REG((unsigned int)REG_CLK+CLKCON) |=0x2000;	
}

static void s3c2440_gpio_cfgpin(void *Regaddr,  unsigned int Addr_offset, unsigned int MaskBit, unsigned int Function)
{
	unsigned int tmp=0;
	
	tmp=REG((unsigned int)Regaddr +Addr_offset);	
	
	if(Addr_offset>0)
	{
		Function &= 3;
		tmp &= ~(3<<MaskBit);		/*used for GPIO Bank B-J, which use the 2 bits Mask*/
	}
	else	
	{
		Function &= 1;
		tmp &= ~(1<<MaskBit);		/*used for GPIO Bank A, which use the 1 bit Mask*/
	}
	
	tmp|= (Function<<MaskBit);	
	REG((unsigned int)Regaddr +Addr_offset)=tmp;
}

static unsigned int s3c2440_gpio_getcfg(void *Regaddr,  unsigned int Addr_offset, unsigned int MaskBit)
{
	unsigned int tmp=0;
	
	tmp=REG((unsigned int)Regaddr +Addr_offset);		
	tmp >>= MaskBit;
	
	if(Addr_offset>0x0c)
		tmp &= 3;	/*used for GPIO Bank B-J, which use the 2 bits Mask*/
	else
		tmp &= 1;	/*used for GPIO Bank A, which use the 1 bit Mask*/

	return tmp;
}

static void s3c2440_gpio_setpin(void *Regaddr,  unsigned int Addr_offset, unsigned int MaskBit, unsigned int to)
{
	unsigned int tmp=0;
	
	tmp=REG((unsigned int)Regaddr +Addr_offset);	
	tmp &= ~(1<<MaskBit);	
	tmp |= (!!to<<MaskBit);
	REG((unsigned int)Regaddr +Addr_offset)=tmp;	
}

static unsigned int s3c2440_gpio_getpin(void *Regaddr,  unsigned int Addr_offset, unsigned int MaskBit)
{
	unsigned int tmp=0;
	
	tmp=REG((unsigned int)Regaddr +Addr_offset);
	tmp &= (1<<MaskBit);	
	return tmp?1:0;
}

static void s3c2440_gpio_pullup(void *Regaddr,  unsigned int Addr_offset, unsigned int MaskBit, unsigned int to)
{
	unsigned int tmp=0;
	
	tmp=REG((unsigned int)Regaddr +Addr_offset);	
	tmp &= ~(1<<MaskBit);
	tmp |= !!to << MaskBit;
	REG((unsigned int)Regaddr +Addr_offset)=tmp;
}

static unsigned int s3c2440_gpio_getpull(void *Regaddr,  unsigned int Addr_offset, unsigned int MaskBit)
{
	unsigned int tmp=0;
	
	tmp=REG((unsigned int)Regaddr +Addr_offset);
	tmp &= (1<<MaskBit);	
	return tmp?1:0;
}

int main(int argc, char* argv[])
{	
	int fd=-1, opt = -1, Bank_num=-1, Addr_offset=-1, MaskBit=-1, Function=-1, to=-1,pullup=-1;
	void* GpioBase = NULL;
	void* CLKBASE = NULL;

	if(argc==2 && !strcmp(argv[1],"-h"))
	{
		print_usage();
		exit(1);
	}
	else if(argc > 5 && argc < 15)
	{
		if(strcmp(argv[1],"-b") || strcmp(argv[3],"-n"))
		{
			fprintf(stdout, "[Error]: '-b' must be used as the first option && '-n' must be used as second the option\n");
			fprintf(stdout, "For Example: %s -b 6 -n 4 -c 1 -w 0 -p 0 -s -r -d\n",APP_NAME);
			print_usage();
			exit(1);
		}
		
		fd = open("/dev/mem", O_RDWR | O_SYNC);
		if(fd<0)
		{
			fprintf(stderr, "open /dev/mem error\n");
			exit(1);
		}

		CLKBASE = mmap(NULL, (CLKREG_EndAddr-CLKREG_StartAddr), PROT_READ|PROT_WRITE, MAP_SHARED,fd, CLKREG_StartAddr & PAGE_MASK);
		if(CLKBASE == NULL || CLKBASE == MAP_FAILED)
		{
			fprintf(stderr, "[Error]: S3C2440 CLKCON base mmap error\n");
			goto failed;
		}
		//fprintf(stdout, "Re-Maped 0x%X to Space Addr:0x%X, Maped Size 0x%X bytes\n",CLKREG_StartAddr,CLKBASE ,(CLKREG_EndAddr-CLKREG_StartAddr));
		
		GpioBase = mmap(NULL, (GPIO_EndAddr-GPIO_StartAddr), PROT_READ|PROT_WRITE, MAP_SHARED,fd, GPIO_StartAddr & PAGE_MASK);
		if(GpioBase == NULL || GpioBase == MAP_FAILED)
		{
			fprintf(stderr, "S3C2440 gpio base mmap error\n");
			goto failed;
		}
		//fprintf(stdout, "Re-Maped 0x%X to Space Addr:0x%X, Maped Size 0x%X\n",GPIO_StartAddr,GpioBase,(GPIO_EndAddr-GPIO_StartAddr));
		
		s3c2440_clkcon_init(CLKBASE);
		
		while ((opt = getopt(argc, argv, "b: n: c: w: p: rsdh")) != -1)
		{
				switch (opt)
				{
					case 'b':  /* Bank num to program */
						Bank_num = strtoul(optarg, NULL, 0);
						if( Bank_num < 0 || Bank_num > 8){
						fprintf(stderr, "[Error]: Please input correct Bank index num, the Bank index num should be 0--8 !\n");
                        			goto failed;
						}
						Addr_offset = Bank_num * 0x10;
						if(Addr_offset==0x80)
							Addr_offset += 0x50;
						
						//fprintf(stdout,"The Addr_offset is 0x%X\n",Addr_offset);
						break;
						
					case 'n':  /*GPIO num in Bank to program, GPIO num is the Mask bit*/
						MaskBit = strtoul(optarg, NULL, 0);
						if( MaskBit < 0 || MaskBit > 25){
						fprintf(stderr, "[Error]: Please input correct GPIO index num, the GPIO index num should be 0--25(max) !\n");
                        			goto failed;
						}
						
						//fprintf(stdout,"The MaskBit is 0x%u\n",MaskBit);
						break;
						
					case 'c': /* The value to config the gpio_config_reg */
						Function = strtoul(optarg, NULL, 0);
						if( Function < 0 || Function > 3){
						fprintf(stderr, "[Error]: Please input correct 'Config_reg' value, the value should be 0x00--0x03 !\n");
                        			goto failed;
						}

						if(Bank_num>0)
						{
							s3c2440_gpio_cfgpin(GpioBase,Addr_offset,MaskBit*2,Function);
							fprintf(stdout,"...Writing the 'Config_reg' to %s...\n",GPIOConStatus[Function]);
						}
						
						else
						{
							s3c2440_gpio_cfgpin(GpioBase,Addr_offset,MaskBit,Function);
							fprintf(stdout,"...Writing the 'Config_reg' to %s...\n",GPIOConStatus[Function+1]);
						}
						break;
						
					case 'w': /* The value to write to the gpio_data_reg*/
						to = strtoul(optarg, NULL, 0);
						if( to < 0 || to > 1){
						fprintf(stderr, "[Error]: Please input correct 'Data_reg' value, the value should be 0x00--0x01 !\n");
                        			goto failed;
						}
											
						s3c2440_gpio_setpin(GpioBase, Addr_offset+4, MaskBit, to);
						fprintf(stdout,"...Writing the 'Data_reg' to %s...\n",GPIODataStatus[to]);
						
						break;

					case 'p': /* The value to write to the gpio_data_reg*/
						pullup = strtoul(optarg, NULL, 0);
						if( pullup < 0 || pullup > 1){
						fprintf(stderr, "[Error]: Please input correct 'Pullup_reg' value, the value should be 0x00--0x01 !\n");
                        			goto failed;
						}
						
						if(Bank_num>0)	
						{
							s3c2440_gpio_pullup(GpioBase, Addr_offset+8, MaskBit, pullup);
							fprintf(stdout,"...Writing the 'Pullup_reg' to %s...\n",GPIOPullupStatus[pullup]);
						}
						else fprintf(stderr,"[Error]: Can't set Pullup for GPIO Bank A%s\n");
						
						break;
						
					case 'r': /* Read the value of the gpio_data_reg*/
						fprintf(stdout,"The 'Data_reg' value is--> %s\n",GPIODataStatus[s3c2440_gpio_getpin(GpioBase, Addr_offset+4, MaskBit)]);
						break;	

					case 's': /* Show the value of the gpio_configure_reg*/
						if(Bank_num>0)
							fprintf(stdout,"The 'Config_reg' value is--> %s\n",GPIOConStatus[s3c2440_gpio_getcfg(GpioBase, Addr_offset, MaskBit*2)]);
						else
							fprintf(stdout,"The 'Config_reg' value is-->%s\n",GPIOConStatus[s3c2440_gpio_getcfg(GpioBase, Addr_offset, MaskBit)+1]);
						
						break;	
						
					case 'd': /* Display the value of the pullup_reg*/
						if(Bank_num>0)
							fprintf(stdout,"The 'Pullup_reg' value is--> %s\n",GPIOPullupStatus[s3c2440_gpio_getpull(GpioBase, Addr_offset+8, MaskBit)]);
						else
							fprintf(stderr,"[Error]: Can't get pullup status for GPIO Bank A\n");
						
						break;	
					
					case 'h': /* help information */
						print_usage();
						goto failed;
						
					default :
						fprintf(stderr, "[Error]: Uncompleted/Unknown option: %c\n", optopt);
						print_usage();
						goto failed;
				}
			}
	}
	else 
	{
		fprintf(stderr, "[Error]: The format of the input options is not correct!\n");
		fprintf(stderr, "[Error]: The quantity of the input options is not correct!\n");
		fprintf(stderr, "[Error]: Please use '%s -h' to get the help information!\n", APP_NAME);
		print_usage();
		exit(1);
	}

	munmap(GpioBase,(GPIO_EndAddr-GPIO_StartAddr)); 
	munmap(CLKBASE,(CLKREG_EndAddr-CLKREG_StartAddr));
	close(fd);
	exit(0);
failed:
	opt =-1;
	Bank_num = -1;
	Addr_offset = -1;
	MaskBit = -1;
	Function = -1,
	to = -1;
	pullup = -1;
	munmap(GpioBase,(GPIO_EndAddr-GPIO_StartAddr)); 
	munmap(CLKBASE,(CLKREG_EndAddr-CLKREG_StartAddr));
	close(fd);
	GpioBase = NULL;
	CLKBASE = NULL;
	exit(1);
}