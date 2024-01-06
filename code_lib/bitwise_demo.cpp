// 8 -> 0b1000
// ffff, ffff

// 16进制，>=8，设为1：< 8，设为0
// 

unsigned int nibbleValue(unsigned int val) {
	// 0xAB895432 -> 0x11110000
	//   88888888
	// A : 1010 1000 -> 1000   1011 1000   5 0101 0000
	//	88880000

	int mask = 0x88888888;
	res = val & mask;
	res >>= 3;


//	0 << 0 
	size_t res = 0;
	int bit = 0;
	while(val) {
		bit = val & 0x1;
		if(bit >= 8) {
			res << 1 | 0x1;
		} else {
			res << 1;
		}
		val >>= 1;
	}
	return res;
}