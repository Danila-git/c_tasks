#include <stdio.h>

void lower(char string[]);

int main()
{
    char string[100];
    printf("Enter string:\n");
    scanf("%99s",string);
    lower(string);
}

void lower(char string[])
{
    int char_amount = 0;
    while(string[char_amount] != '\0')
       {
     (string[char_amount] >= 65 && string[char_amount] <= 90)
       ? (string[char_amount] += 32)
       : string[char_amount];
       char_amount += 1;
       }
       printf("%s" ,string);
}


