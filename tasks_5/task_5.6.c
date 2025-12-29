#include <stdio.h>
#include <string.h>

#define MAXLENGTH 100
void reverse(char *s);

int main()
{
    char str[MAXLENGTH];
  printf("Enter string: ");
  scanf("%s",str);
  reverse(str);
  printf("Result : %s",str);
}

void reverse(char *s)
{
   int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
     c = *(s+i);
     *(s+i) = *(s+j);
     *(s+j) = c;
    }
}

//сделано