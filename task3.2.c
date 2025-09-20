#include <stdio.h>

void escape(char s[], char t[]);


int main()
{
  char result_string[100], start_string[100];
  scanf("%s",start_string);
  escape(start_string, result_string);
}


void escape(char s[], char t[])
{
    int i = 0, space_amount = 0;
    while (s[i] != EOF)
    {
        switch (s[i])
        {
        case ' ':
            space_amount += 1;
            if(space_amount >= 4)
            {
                for(int j = 3; j <=1; j += 1)
                {
                    t[i-j] = ' ';
                }
                t[i] = '\\t';
                space_amount = 0;
            }
            break;
        case '\n':
            t[i] = '\\n';
            break;
        default:
            t[i] = s[i];
            break;
        }
    }
    printf("%s",t);
}
