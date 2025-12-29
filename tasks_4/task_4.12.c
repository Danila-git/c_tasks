#include <stdio.h>

#define MAXSIZE 50

int counter = 0;

void itoa_recursive(char val[], int num);

int main()
{
    char val[MAXSIZE];
    int num;
    
    while(1)
    {
    printf("Enter word\n");
    scanf("%d",&num);
    itoa_recursive(val,num);
    val[counter] = '\0';
    printf("\nResult : %s\n",val);
    counter = 0;
    }
}

void itoa_recursive(char val[], int num)
{
    if(num < 0)
    {
       num = -num;
       val[counter++] = '-';
    }
    if(num/10 != 0)
    {
        itoa_recursive(val,num/10);
    }
    val[counter++] = (num % 10) + '0';
}

//сделано