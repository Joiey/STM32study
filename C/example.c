#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *src = "hello,world";
    int len = strlen(src);
    char *dest = (char *)malloc(len + 1); //要为分配一个空间
    char *d = dest;
    char *s = &src[len - 1]; //指向最后一个字符
    while (len-- != 0)
    {
        *d++ = *s--;
    }
    *d = 0; //尾部要加’\0’
    printf("%s\n", dest);
    free(dest);  // 使用完，应当释放空间，以免造成内存汇泄露
    dest = NULL; //防止产生野指针
    return 0;
}