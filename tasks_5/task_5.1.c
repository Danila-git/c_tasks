#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 10
int getch (void);
void ungetch (int c);
int getint(int *pn);

int main()
{
    int data = 0;
while(1)
{
    printf("%d\n",getint(&data));
    printf("%d\n",data);
}
    
}

int getint(int *pn)
{
int c, sign;
while (isspace(c = getch()))
;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' ) {
    ungetch(c); 
    return 0;
    }
sign = (c == '-' ) ? -1 : 1;
    if (c == '+' || c == '-')
     {
        c = getch();
     }
     if(!isdigit(c))
     {
        (sign == 1) ? ungetch('+') : ungetch('-');
        return 0;
     }
for (*pn = 0; isdigit(c); c = getch())
    {
    *pn = 10 * *pn + (c - '0' ) ;
    }

*pn *= sign;
if (c != EOF)
{
ungetch(c);
}
return c;
}
int inde = 0;
char buf[BUFSIZE];
int getch(void)
{
    return (inde > 0) ? buf[--inde] : getchar();
}

void ungetch(int c)
{
  if(inde < BUFSIZE)
  {
    buf[inde++] = c;
  }
}