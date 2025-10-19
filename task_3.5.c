#include <stdio.h>

void itob(int n, char s[], int b);

int main()
{
    int n, b;
    char s[50];
    printf("Enter number that you want convert:\n");
    scanf("%d", &n);
    printf("Enter the type of num(2,8,16):\n");
    scanf("%d", &b);
    itob(n,s,b);
    printf("%s", s);
}

void itob(int n, char s[], int b)
{
    int k;
    switch (b)
        {
        case 2:
      for(k = 0; n != 0;k+=1)
      {
          if(n % 2)
          {
            s[k] = '1';
          }else
          {
            s[k] = '0';
          }
          n /= 2;

      }
      if(n < 0)
      {
          s[k] = '1';
      }else
      {
          s[k] = '0';
      }
            break;
        case 8:
            break;
        case 16:
            break;
        }
}
