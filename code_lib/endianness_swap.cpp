unsigned int swapEndian(unsigned int x)
{
    return ((x>>24)&0xff) | // Move byte 3 to byte 0
           ((x<<8)&0xff0000) | // Move byte 1 to byte 2
           ((x>>8)&0xff00) | // Move byte 2 to byte 1
           ((x<<24)&0xff000000); // Move byte 0 to byte 3
}