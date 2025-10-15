#include <stdio.h>

void lower(char string[]);

int main()
{
    char string[100];
    printf("Enter string:\n");
    fgets(string, sizeof(string), stdin);
    lower(string);
}

void lower(char string[])
{
    int char_amount = 0;
    while(string[char_amount] != '\0')
       {
     (string[char_amount] >= 'A' && string[char_amount] <= 'Z')
       ? (string[char_amount] += ('a'-'A'))
       : string[char_amount];
       char_amount += 1;
       }
       printf("%s" ,string);
}

//сделано
