#include <iostream>

class DeviceTester {
public:
    /* 
        why using virtual funciton for destructor? Without `virtual`,  
        It will only call base class destrctor when calling destructor 
        `delete IT`.
    */
    virtual ~DeviceTester() {
        std::cout << "closing DeviceTester..." << std::endl;
    }

    virtual void testDevice() = 0;  // pure virtual funciton
};

class I2CDeviceTester : public DeviceTester {
public:
    void testDevice() override {
        std::cout << "Intializing and testing I2C device..." << std::endl;
        i2c_init();
        i2c_test();
        std::cout << "I2C device test completed." << std::endl;
    }

    ~I2CDeviceTester() {
        std::cout << "closing I2C device..." << std::endl;
    }

private:
    void i2c_init() {
        std::cout << "i2c init" << std::endl;
    }
    void i2c_test() {
        std::cout << "i2c test" << std::endl;
    }
};

class SPIDeviceTester : public DeviceTester {
public:
    void testDevice() override {
        std::cout << "Initializing and testing SPI device..." << std::endl;
        // spi_init();
        // spi_test();
        std::cout << "SPI device test completed" << std::endl;
    }

    ~SPIDeviceTester() {
        std::cout << "closing SPI device..." << std::endl;
    }
};

/* 
    不用动态内存管理。对象的生命周期由其在`main`函数中的作用域决定 
    基类中的机构函数不需要设置成虚函数
    不需要自己调用析构函数
*/
int main(void) {
    I2CDeviceTester IT;
    SPIDeviceTester ST;
    
    DeviceTester *dt;
    dt = &IT;
    dt->testDevice();

    dt = &ST;
    dt->testDevice();

    return 0;
}

/* 
    使用动态内存管理，自己来控制对象的生命周期。
    注意基类中的析构函数要使用虚函数
    需要自己来调用析构函数
 */
/* int main(void) {
    DeviceTester* IT = new I2CDeviceTester();
    IT->testDevice();
    // delete IT;

    IT = new SPIDeviceTester();
    IT->testDevice();
    // delete IT;

    return 0;
} */