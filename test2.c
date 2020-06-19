#include <stdio.h>

int main(int argc, char const *argv[])
{
    char buf[] = "{'led2':1}";
    int num,value;

    printf("buf = %s\n", buf);

    num = buf[5] - '0';
    value = buf[8] - '0';
    printf("num = %d, value = %d\n", num, value);

    return 0;
}
3：nihao qingdao
