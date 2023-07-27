

#define SOUND_CTL *(volatile unsigned long *)0x80000000

#define ENABLE_BIT 0x07
#define VOLUME_START_BIT 0x0
#define VOLUME_END_BIT 0x7

bool controlSound(int volume, bool enable) {
    int i;
    int data = 0;
    int max = ~0;
    int mask = 0;

    if(enable == True) {
        *reg |= (1 << ENABLE_BIT);
    } else {
        *reg &= ~(1 << ENABLE_BIT);
    }

    if(volume < 0 && volume > 255) {
        return false;
    }

    // set the volume:  0000 1111 0000   例如：第四位到第七位 是音量设置位
    // 思路是将音量位全部清零 - 借助mask, 构造出除了音量位是0，其他全部是1的mask
    
    // 1. 将音量位左边的位，置为1
    int left = max - ((1 << VOLUME_END_BIT) - 1);
    
    // 2. 将音量位右边的位，置为1
    int right = (1 << VOLUME_END_BIT) - 1;

    // 3. mask
    mask = left | right;

    *reg &= mask;

    data = volume << VOLUME_START_BIT;
    *reg |= data;

    return true;
}