#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    
    int N;
    cout << "Please enter the number: ";
    cin >> N;
    cout << endl;
 
    //十进制转十六进制的声明和调用
    void  convert_10_to_16(int num);
    convert_10_to_16(N);
}
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
void convert_10_to_16(int num)
{
    vector<int> ivec;
    int Num = num;
    while (num != 0)
    {
        ivec.push_back(num % 16);
        num = num / 16;
    }
 
    vector<int>::size_type sz = ivec.size();
    vector<string> ivec2;
    int m = 0;
    string s;
    for (vector<int>::size_type index = 0; index != sz; ++index)
    {
        if (ivec[sz - 1 - index] > 9)
        {   
            m = ivec[sz - 1 - index] + 55;
            s = m+'0'-'0';
            ivec2.push_back(s);
        }
        else
        {
            s = ivec[sz - 1 - index] + '0';
            ivec2.push_back(s);
 
        }         
    }
    
 
    cout << Num << "十进制转十六进制后为：";
    for (auto item : ivec2)
        cout << item;
    cout << endl << endl;
}


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
 
    double convert_16_to_10();
    convert_16_to_10();
 
    return 0;
}

//************************************************************************************
十六进制转换为十进制
//************************************************************************************
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
double convert_16_to_10()
{
    //输入十六进制数并存储在string变量str2中
    cout << "Please enter the ShiLiuJInZhi numbers:  " << endl;
    char s;
    string str2;
    while (cin >> s)
    {
        str2.push_back(s);
    }
 
 
    double sum = 0, times;
    double m;
    string::size_type sz = str2.size();
    for (string::size_type index = 0; index != sz; ++index)
    {
        //变为小写，这个思路很好
        str2[index] = tolower(str2[index]);
        if (str2[index] >= 'a' && str2[index] <= 'f')
        {
            //这里让a~f进行转换为数字字符，很奇妙
            m = str2[index] - 'a' + 10;
            //求幂次方
            times = pow(16, (sz - 1 - index));
            sum += m * times;
 
        }
 
        else if (isdigit(str2[index]))
        {
            //需要将字符类型转换为数字类型
            //因为0的ASCII码是48，所以转换为相应的数字，减去48即可
            m= str2[index] - 48;
            times = pow(16, (sz - 1 - index));
            sum += m * times;
            
        }
        else
        {
            cout << "无法识别的十六进制!";
            break;
        }
    }
    cout << "16进制转10进制为： ";
    cout << sum << endl;
    return 0;
}