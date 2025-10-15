#include <stdio.h>
#define MAXSIZE 1000

int getline(char string[]);

int main()
{
    int length;
    char string[MAXSIZE];
    //пока строка больше 0 символов выполняем дальше
    while((length = getline(string)) != 0)
    {
        //если массив больше 80 символов, то печатаем строку
        if(length > 80)
        {
                printf("%s\n",string);
        }
    }
    return 0;
}

//считываем строку до символа новой строки или конца файла
int getline(char string[])
{
    int i = 0;
    char c = 0;
    while((c = getchar()) != '\n' && c != EOF)
          {
              string[i] = c;
              i+=1;
          }
          string[i] = '\0';
          return i;
}


//сделано
