#include <stdio.h>

#define MAXLENGTH 1000

int any(char s1[], char s2[]);
void my_getline(char string[]);

int main()
{
    char string1[MAXLENGTH];
    char string2[MAXLENGTH];
    my_getline(string1);
    my_getline(string2);
    printf("%d",any(string1,string2));
}

int any(char s1[], char s2[])
{
    for(int i = 0; s1[i] != '\0'; i+=1)
    {
        for(int k = 0; s2[k] != '\0'; k+=1)
        {
            if(s2[k] == s1[i])
            {
                return i+1;
            }
        }
    }
    return -1;
}

void my_getline(char string[])
{
    char c;
    int i = 0;
    while((c = getchar()) != EOF && c != '\n' && c != ' ')
    {
        string[i] = c;
        i+=1;
    }
    string[i] = '\0';
}

//�������
