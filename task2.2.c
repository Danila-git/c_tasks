#include <stdio.h>

#define lim 1000
int s[lim];

int main()
{

int c;
int i = 0;
//первый вариант
while(1)
{
if(i < lim - 1)
{
    if((c = getchar()) != EOF)
    {
        if(c != '\n')
        {
            s[i] = c;
        }
    }
}
i += 1;
}

//второй вариант
/*while(1)
{
if(i >= lim - 1) {
     break;
    }
if((c = getchar()) = EOF)
    {
    break;
    }
if(c = '\n')
    {
    break;
    }
s[i] = c;
i += 1;
}*/
}

