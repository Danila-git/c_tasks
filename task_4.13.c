#include <stdio.h>
#include <string.h>

#define MAXLENGTH 130

void reverse(char str[],int left_letter,int right_letter);


int main()
{
    char str[MAXLENGTH];
    while(1)
    {
    printf("Enter string: \n");
    scanf("%s",str);
    reverse(str,0,(strlen(str) - 1));
    printf("Result: %s\n",str);
    }
}

void reverse(char str[],int left_letter,int right_letter)
{
    if(left_letter < right_letter)
    {
        reverse(str,left_letter + 1,right_letter - 1);
    }
    int c = 0;
    c = str[left_letter];
    str[left_letter] = str[right_letter];
    str[right_letter] = c;

}

//сделано