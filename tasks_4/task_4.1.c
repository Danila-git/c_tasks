#include <stdio.h>

#define MAXSTRLENGTH 300
#define MAXPATLENGTH 30

int the_most_right = -1;

int my_getline(char s[]);
int strindex(char str[], char pattern[]);

int main()
{
    char str[MAXSTRLENGTH], pattern[MAXPATLENGTH];
    printf("Enter pattern: ");
    scanf("%s",pattern);
    while(getchar() != EOF)
    {
        my_getline(str);
       printf("The most right enter: %d\n",strindex(str,pattern));
    }

}



int strindex(char str[], char pattern[])
{
    int k,j = 0;
   for(int i = 0; str[i] != '\0'; i+=1)
   {
       for(j = i, k = 0; pattern[k] != '\0' && str[j] == pattern[k]; j+=1, k+=1)
;
       if( k>0 && pattern[k] == '\0')
       {
           if(i > the_most_right)
           {
               the_most_right = i;
             return i+1;
           }
           else
           {
               return the_most_right+1;
           }
       }
   }
    if (the_most_right == -1) {
        return -1;
    } else {
        return the_most_right+1;
}
}

int my_getline(char s[])
{
    int c, i = 0;
    while((c = getchar()) != EOF && c != '\n' && i < MAXSTRLENGTH - 2)
    {
        s[i++] = c;
    }
    if(c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}

//сделано