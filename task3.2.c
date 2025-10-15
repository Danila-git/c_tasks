#include <stdio.h>

void escape(char s[]);
void getline(char text[]);

int main()
{
  char start_string[100];
  getline(start_string);
  escape(start_string);
}


void escape(char s[])
{
    char t[100];
    int j = 0,i = 0;
    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case '\t':
                t[j] = '\\';
                t[++j] = 't';
                j+=1;
                i+=1;
            break;
        case '\n':
            t[+j] = '\\';
            t[++j] = 'n';
            i+=1;
            j+=1;
            break;
        default:
            t[j++] = s[i++];
            break;
        }
    }
    t[j] = '\0';
    printf("%s",t);
}

void getline(char text[])
{
    int c,i = 0;
    while((c = getchar()) != EOF)
    {
        text[i] = c;
        i+=1;
    }
    text[i] = '\0';
}

//сделано
