#include <stdio.h>

int main()
{
    int c;
    int str[1000];
    int i = 0;

    while((c = getchar()) != EOF && i < 998)
    {
        if(c == '\t')
        {
            str[i] = '\\';
            str[i+1] = 't';
            i += 2;
        }
        else if(c == '\b')
        {
            str[i] = '\\';
            str[i+1] = 'b';
            i += 2;
        }
        else if(c == '\\')
        {
            str[i] = '\\';
            str[i+1] = '\\';
            i += 2;
        }
        else
        {
            str[i] = c;
            i += 1;
        }
    }
    str[i] = '\0';

    for(int counter = 0; counter < i; counter += 1)
    {
        putchar(str[counter]);
    }
}
//сделано
