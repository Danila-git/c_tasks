#include <stdio.h>
#define MAXLENGTH 8000

int get_text(char text[]);
void change_text(char text[],char result_text[], int length);

int main()
{
    int length;
    char text[MAXLENGTH];
    char result_text[MAXLENGTH];

    length = get_text(text);
    change_text(text,result_text, length);
    printf("%s", result_text);
    return 0;
}

int get_text(char text[])
{
    int c;
    int length = 0;
    while((c = getchar()) != EOF)
    {
        text[length] = c;
        length+=1;
    }
    text[length] = '\0';

    return length;
}

void change_text(char text[],char result_text[], int length)
{
        int k = 0;
   for(int i = 0; i < length; i+=1)
   {
       if(text[i] == '/')
       {
           i+=1;
                if(text[i] == '/')
                {
                while(text[i] != '\n')
                {
                    i+=1;
                }
                result_text[k++] = text[i];
                }else if(text[i] == '*')
                {
                    while(text[++i] != '*' && text[++i] != '/')
                    {
                        i--;
                    }
                    i+=2;
                result_text[k++] = text[i];
                }else
                {
                result_text[k++] = text[i];
                }
       }
       else
       {
           result_text[k++] = text[i];
       }

   }
}

//сделано
