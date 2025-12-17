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
    itob(n, s, b);
    printf("%s", s);
}

void itob(int n, char s[], int b)
{
    int k;
    switch (b)
    {
    case 2:
        if (n < 0)
        {
            putchar('1');
        }
        else
        {
            putchar('0');
        }
        do
        {
            if (n % 2)
            {
                putchar('1');
            }
            else
            {
                putchar('0');
            }
        } while ((n /= 2) != 0);
        break;
    case 8:
        break;
    case 16:
        break;
    }
}
