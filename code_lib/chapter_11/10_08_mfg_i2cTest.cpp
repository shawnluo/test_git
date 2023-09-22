

size_t i2c_read(unsigned int bus, unsigned int addr, unsigned int offset) {
    // open();
    ...
    // close();
    return value;
}

// bus : 0, 2, 3
unsigned int bus[3] = {0, 2, 3};

// bus 0: {0x10, 0x3}, {0x20, 0x5}, {0x50, 0x8};
// bus 2: {0x20, 0x1}, {0x40, 0x2, {0xa0, 0x8};
// bus 3: {0x20, 0x40, 0xa0};
unsigned int addr;
unsigned int offset;
unsigned pos[3][2];
size_t res = {11, 9, 0};

// test i2c interface
bool i2c_test() {    
    for(int i = 0; i < sizeof(bus) / sizeof(bus[0]); i++) {
        for(int j = 0; j < pos; j++) {
            val = i2c_read(bus[i], pos[i][0], pos[i][1]);
            if(val != res[i]) {
                saveLog("i2c_read failed", bus[i], pos[j]);
                return false;
            } else {
                saveLog("i2c_read passed", bus[i], pos[j]);
            }
        }
    }
    return true;
}