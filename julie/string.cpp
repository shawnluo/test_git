#include <iostream>
#include <string>
#include <algorithm>

//#define VER1
//#define VER2
//#define VER3
#define VER4

#ifdef VER1
int main()
{
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    std::reverse(str.begin(),str.end());
    std::cout << "Print the reversed string " << str << std::endl;
    return 0;
}
#elif VER2
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cerr << "The argc is < 2" << "We need to input a string" << std::endl;
        return 1;
    }
    std::string str = argv[1];
    std::cout << "The original input string is " << str << std::endl;
    std::reverse(str.begin(),str.end());
    std::count << "The reversed string is: " << str << std::endl;
    return 0;

}
#elif VER3
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout << "argc is < 2" << "we need to input a valid string" << std::endl;
        return 1;
    }
    std::string str = argv[1];
    int len = str.length();
    int tmp = 0;
    for(int i = 0; i < len;i++)
    {
        tmp = str[i];
        str[len-1-i] = str[i];
        str[i] = tmp;
    }
    return 0;
}
#elif VER4
int main(int argc, char *argv[])
{
    if(argc < 2)
    std::cout << "argc is < 2" << "We need to input a valid string" << std::end1;
    std::string str;
    str = argv[1];

    int start = 0;
    int end = str.length()-1;
    int tmp = 0;
    while(start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;

        start++;
        end--;
    }
    return 0;
#endif