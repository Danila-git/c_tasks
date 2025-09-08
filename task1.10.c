#include <stdio.h>

int main()
{
    int c,space = 0,i = 0;
    int str[1000];
    while((c = (getchar())) != EOF)
    {
        if(c == '\t')
        {
            str[i] = '\\t';
            i += 1;
        }else if(c == '\b')
        {
            str[i] = '\\b';
            i += 1;
        }else if(c == '\\')
        {
            str[i] = '\\';
            i += 1;
        }else{
            str[i] = c;
            i += 1;
        }
    }
    for(int counter = 0; counter <= i; counter += 1)
    {
        putchar(str[counter]);
    }
}
