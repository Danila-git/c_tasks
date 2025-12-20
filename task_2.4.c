#include <stdio.h>

void my_getline(char string[]);
void squeeze(char s1[], char s2[]);
void char_delete(int pos, char string[]);

int main()
{
    char string1[100];
    char string2[100];
    my_getline(string1);
    my_getline(string2);
    squeeze(string1, string2);
    return 0;
}

void my_getline(char string[])
{
    int c;  
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && c != ' ')
    {
        string[i] = (char)c;
        i += 1;
    }
    string[i] = '\0';
}

void squeeze(char s1[], char s2[])
{
    for (int i = 0; s2[i] != '\0'; i += 1)
    {
        for (int j = 0; s1[j] != '\0'; j += 1)
        {
            if (s1[j] == s2[i])
            {
                char_delete(j, s1);
                j -= 1;
            }
        }
    }
    printf("%s", s1);
}

void char_delete(int pos, char string[])
{
    for (int k = pos + 1; string[k] != '\0'; k += 1)
    {
        string[pos++] = string[k];
    }
    string[pos] = '\0';
}