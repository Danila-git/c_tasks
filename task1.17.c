
//не сделано

#include <stdio.h>
#define MAXLINE 1000 /* максимальный размер вводимой строки */
int getline(char line[] int MAXLINE);

main()
{
int length = 0;

while((int c = getchar()) != EOF)
{
    line[length] = c;
    length+= 1
}
if(length > 80)
{
    for(int j= 0; j <= length; j += 1)
    {
        putchar(line[j]);
    }
}
return 0;
}

int line_check(char line[])
{

}

