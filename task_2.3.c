#include <stdio.h>

int main()
{

    char string1[100];
    char string2[100];
    scanf(string1);
    scanf(string2);
    squeeze(string1, string2);
}


void squeeze(char s1[],char s2[])
{
    int i,j,k, delet = 0;
    for(i = k = 0; s1[i] != '/0'; i++)
    {
        for(j = 0; s2[j] != '/0'; j++)sdfghjk
        {
            if(s1[i] = s2[j])
            {
                delet = 1;
            }
        }
        if(!delet)
        {
        s1[k++] = s1[i];
        }
    }
}
