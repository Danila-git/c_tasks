#include <stdio.h>

#define MAXLENGTH 1000

void getline(char string[]);
void htol(char string[]);

int main()
{
    char text[MAXLENGTH];

    getline(text);
    htol(text);
}

void getline(char string[])
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

void htol(char string[])
{
    int digit, result = 0;
    for(int i = 0; string[i] != '\0'; i+=1)
    {
        if(string[i] == '0')
        {
            i+=1;
            if(string[i] == 'x' || string[i] == 'X')
            {
                i+=1;
                while(string[i] != '\0')
                {
                    if (string[i] >= '0' && string[i] <= '9') {
            digit = string[i] - '0';
        } else if (string[i] >= 'a' && string[i] <= 'f') {
            digit = string[i] - 'a' + 10;
        } else if (string[i] >= 'A' && string[i] <= 'F') {
            digit = string[i] - 'A' + 10;
        }
        result = result * 16 + digit ;
        i+=1;
            }
               printf("%d", result);
        }
    }
}
}

//сделано
