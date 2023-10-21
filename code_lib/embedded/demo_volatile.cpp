

/*
    implement a voice control API
    1. register address
    2. Volume can be 0 - 255

    bool ControlSound(int Volume, bool Enable)
*/


#define SOUND_CTL (*(volatile unsigned long *)0x80000000)

#define ENABLE_BIT 0x07
#define VOLUME_START_BIT 0x0
#define VOLUME_END_BIT 0x7
bool ControlSound(int Volume, bool Enable) {
    int i;
    int data = 0;
    int max = ~0;
    //int max = INT_MAX;
    int left = 0;
    int right = 0;
    int mask = 0;
       
    if(Enable == TRUE) {
       SOUND_CTL |= (1 << ENABLE_BIT);
    } else {
        SOUND_CTL &= ~(1 << ENABLE_BIT);
    }
    
    //set the volume
    if((Volume >= 0) && (Volume <= 255)) {
        // there're 2 ways to set the register
        /*
            ------------ way1: set the bits one by one
        */
        #ifdef way1     
        for(i = VOLUME_START_BIT;i <= VOLUME_END_BIT;i++) {
            data |= (Volume >> i);
            data <<= 1; 
        }
        #endif

        /*
            ------------ way2: use mask to do the job
        */
        //1. set mask
        left = max - ((1 << VOLUME_END_BIT) - 1);
        right = (1 << VOLUME_END_BIT) - 1;
        mask = left | right;

        //mask = 0;
        //mask = (0xff) << 8;
        
        SOUND_CTL &= mask;

        //set volume
        data = Volume;
        data <<= VOLUME_START_BIT;

        //write data into register
        SOUND_CTL |= data;

        return TRUE;
    } else {
        return FALSE;
    }
}

int CountBits(int num) {
    int count = 0;

    while(num) {
        num &= (num - 1);
        count++;
    }
    return count;
}



Your function receives 10 numbers one after the other. You need to check whether each number is a palindrome.
Maintain a queue where you need to push the number if it is a palindrome. Disregard the number if it not a palindrome.
Use linked list.

For eg: 12321
    34265
    56765
    36266
    66666
    .....
The queue should have <12321> <56765> <66666>



#define YES 1
#define NO 0
int checkPalindrome(unsigned int number) {
    int ret = 0, sign = number >> 31;
    int save = number;
      
    //reverse the number
    
    while(number != 0)
    {
        ret = ret * 10 + number % 10;
        number = number / 10;
    }
    
    if(sign != (ret >> 31))
    {
        exit(1);
    }
    
    if(save != ret)
    {
        return NO;
    }
    else
    {
        return YES;
    }
}

int My_Sorting(int array[], int muber)
{
    
}



typedef struct node
{
    int num;
    struct node *next;
} Node, *pNode;

#define LEN sizeof(struct node)

//Node *Create_Linkedlist(int arrary[], int number)
pNode Create_Linkedlist(int arrary[], int number)
{
    pNode pHead = NULL, p = NULL;
    
    while(number--)
    {
        p = (pNode)malloc(LEN);
        p->num = number;
        p->next = pHead;
        phead = p;
    }
    
    return pHead;
}


//1. put all the numbers into a array;
//2. check  the number is palindrome or not one by one.



//rotten fruit
//0 no fruit
//1 fresh fruit
//2 rotten fruit
2 1 -> 2 2
1 1    2 2
return 1

2 1    2 2    2 2
1 1 -> 2 1 -> 2 2
1 0    2 0    2 0
return 2

2 1 0     2 2 0
1 0 1  -> 2 0 1
1 1 0     2 2 0
return -1