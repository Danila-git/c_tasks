#include <stdio.h>

void my_getline(char text[]);
void expand(char start_text[], char result_text[]);

int main()
{
    char start_text[100], result_text[600];
    my_getline(start_text);
    expand(start_text, result_text);
    printf("%s", result_text);
}

void expand(char start_text[], char result_text[])
{
    int j = 0, i = 0;
    while(start_text[i] != '\0')
    {
        if(start_text[i] == '-')
        {
            if(('a' <= start_text[i-1] <= 'z') && ('a' <= start_text[i+1] <= 'z'))
            {
              j-=1;
              for(int k = start_text[i-1];k <= start_text[i+1];k+=1)
              {
                  result_text[j++] = k;
              }
              i+=2;
            }else if(('A'<= start_text[i-1] <= 'Z') && ('A' <= start_text[i+1] <= 'Z'))
            {
                j-=1;
              for(int k = start_text[i-1];k <= start_text[i+1];k+=1)
              {
                  result_text[j++] = k;
              }
              i+=2;
            }else if(('0' <= start_text[i-1] <= '9') && ('0' <= start_text[i+1] <= '9'))
            {
               j-=1;
              for(int k = start_text[i-1];k <= start_text[i+1];k+=1)
              {
                  result_text[j++] = k;
              }
              i+=2;
            }else{
             result_text[j++] = start_text[i++];
            }
        }else
        {
            result_text[j++] = start_text[i++];
        }
    }
}
void my_getline(char text[])
{
    int c,i = 0;
    while((c = getchar()) != EOF)
    {
        text[i] = c;
        i+=1;
    }
    text[i] = '\0';
}

//�������

