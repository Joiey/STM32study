#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(void)
{
    char *src = "hello world";
    int len = strlen(src);
    char *dest = (char *)malloc(len + 1); //要为分配一个空间
    char *d = dest;
    char *s = &src[len - 1]; //指向最后一个字符
    while (len-- != 0)
    {
        *d++ = *s--;
    }
    *d = 0; //尾部要加’\0’
    printf("dest is %s", dest);
    free(dest);
    dest = NULL;
}
int main(void)
{
    reverseString();
    return 0;
}