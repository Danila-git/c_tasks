#include <stdio.h>
#include <string.h>

#define MAXSIZE 300

int my_strend(char *s, char *t);

int main()
{
   char s[MAXSIZE],t[MAXSIZE-100];
   printf("Enter mas s: ");
   scanf("%s",s);
    printf("Enter mas t: ");
    scanf("%s",t);
   printf("1 if true else 0: %d",my_strend(s,t));
}

int my_strend(char *s,char *t)
{
    int overlap_amount = 0;
    int t_length = strlen(t);
   //index in S where should start T
   char* index = strlen(s)-t_length + s;
   while(*t != '\0' && *index != '\0' && (*index++ == *t++) )
   {
    overlap_amount+=1;
   }
    if(overlap_amount == t_length)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//сделано