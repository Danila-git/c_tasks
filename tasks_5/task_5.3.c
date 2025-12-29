#include <stdio.h>
#include <string.h>

#define MAXSIZE 300

void my_strcat(char *s, char *t);

int main()
{
   char s[MAXSIZE],t[MAXSIZE-100];
   printf("Enter mas s: ");
   scanf("%s",s);
    printf("Enter mas t: ");
    scanf("%s",t);
   my_strcat(s,t);
   printf("RESULT: %s",s);
}

void my_strcat(char *s,char *t)
{
    if((MAXSIZE - strlen(s)) > strlen(t))
    {
    while((*s++) != '\0');  
    s -= 1;
    while(*s++ = *t++);
    }
    else{
        printf("Exception, not enough space in the array\n");
    }
}

//сделано