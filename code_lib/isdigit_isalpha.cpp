
int main() {
    char c;
    c = getchar();
    //来判断是否为数字，如果是数字那么会返回非0
    if(isdigit(c) != 0)
        printf("是数字\n") ;
    //来判断是否为字母，如果是字母那么返回非0
    else if(isalpha(c) != 0)
        printf("是字母\n"); 
    else
        printf("是特殊字符\n");

    return 0;
}