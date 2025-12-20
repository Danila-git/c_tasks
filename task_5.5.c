#include <stdio.h>
#include <string.h>

#define MAXSIZE 300

char* my_strcat(char *s, char *t, int n);
char* my_strcpy(char*s,char *t, int n);
char my_strcmp(char* s, char* t, int n);

int main()
{
  char s[MAXSIZE],t[MAXSIZE-100];
  scanf("%s",s);
  scanf("%s",t);
  printf("%s\n",my_strcat(s,t,3));
  printf("%s\n",my_strcpy(s,t,4));
  printf("%d\n",my_strcmp(s,t,4));
}

//cat t into s 
char* my_strcat(char *s,char *t, int n)
{
    char* start_s_pos = s;
    //check is enought place in array
    if((MAXSIZE - strlen(s)) > strlen(t))
    {
    while((*s++) != '\0');  
    s -= 1;
    while( (n--) > 0 && (*s++ = *t++));
    t = '\0';
    return start_s_pos;
    }
    else{
        printf("Exception, not enough space in the array\n");
    }
}

//copy n element from t to s
char* my_strcpy(char*s,char *t, int n)
{
    char* start_s_pos = s;
    while((n--) > 0 && (*s++ = *t++));
    *s = '\0';
    return start_s_pos;
}

char my_strcmp(char* s, char* t, int n)
{
   while((n--) > 0 && *s != '\0' && *t != '\0' && *s++ == *t++);
   return *s - *t;
}

//сделано