#include <stdio.h>

#define MAXLENGTH 3000

const tab_width = 4;
int char_amount_of_start_text = 0;

void my_getline(char text[]);
void detab(char start_text[], char result_text[]);

int main()
{
    char start_text[MAXLENGTH];
    char result_text[MAXLENGTH+3000];
    my_getline(start_text);
    detab(start_text, result_text);
}

void my_getline(char text[])
{
    int c;
    while((c = getchar()) != EOF && char_amount_of_start_text != MAXLENGTH)
    {
        text[char_amount_of_start_text] = c;
        char_amount_of_start_text+=1;
    }
    text[char_amount_of_start_text] = '\0';
}

void detab(char start_text[], char result_text[])
{
    int i = 0, k = 0;
    while(start_text[i] !=  '\0')
    {
        if(start_text[i] == '\t')
        {
            int tab_stop = tab_width - (i % tab_width);
                while(tab_stop > 0)
                {
                    result_text[k] = ' ';
                    k+=1;
                    tab_stop-=1;
                }
        }else
        {
            result_text[k] = start_text[i];
            k+=1;
        }
        i+=1;
    }
      result_text[k] = '\0';
}

//�� �������
