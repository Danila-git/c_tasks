#include <stdio.h>

void reverse(int char_amount, char start[],char result[]);
int getline(char string[], int lim);

int main()
{
    char start_string[1000],result_string[1000];
    int symb;
    printf("Enter your string: \n");
    symb = getline(start_string,1000);
    reverse(symb,start_string,result_string);
    printf("Result string: \n%s", result_string);
}


void reverse(int char_amount, char start[],char result[])
{
 for(int i = 0; i < char_amount; i+=1)
 {
     result[i] = start[char_amount - 1 - i];
 }
 result[char_amount] = '\0';
}

int getline(char string[], int lim)
{
    int c, i = 0;
  for(; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
  {
      string[i] = c;
  }
  string[i] = '\0';
  return i;
}

//сделано
