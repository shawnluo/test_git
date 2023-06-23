#include <iostream>
using namespace std;

/*
测试类指针
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


using namespace std;

class CClassPointer
{
    public:
        CClassPointer();
        ~CClassPointer();
        void PrintfFunc(char* data);
        CClassPointer* m_class;
        
    private:

    protected:
        

};

CClassPointer::CClassPointer()
{
    m_class = NULL;
}

CClassPointer::~CClassPointer()
{
    if(NULL != m_class)
    {
        delete m_class;
    }
}

void CClassPointer::PrintfFunc(char* data)
{
    if(data != NULL)
    {
        printf("data:%s\n",data);    
    }
    else
    {
        printf("printf data NULL\n");
    }
}

// 这个类没有实例化，只初始化这个类指针，同时这个类指针复制为0；
// 下面使用这个类指针，就可以直接调用这个类里面的函数
int main()
{
    CClassPointer * classPointer = 0; 
    //classPointer = new CClassPointer();
    //if(classPointer != NULL)
    {
        classPointer->PrintfFunc(NULL);
    }
    printf("end\n");
    

    return 0;
}