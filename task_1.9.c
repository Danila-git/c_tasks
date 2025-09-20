#include <stdio.h>

int main()
{
    int c,space = 0,i = 0;
    int str[1000];
    while((c = (getchar())) != EOF)
    {
        if(c == ' ')
        {
            space += 1;
        }else
        {
            space = 0;
        }
        if(space <= 1)
           {
            str[i] = c;
            i += 1;
           }
    }
    for(int counter = 0; counter <= i; counter += 1)
    {
        putchar(str[counter]);
    }
}

//сделано

