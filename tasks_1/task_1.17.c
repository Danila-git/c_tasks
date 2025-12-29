#include <stdio.h>
#define MAXSIZE 1000

int my_getline(char string[]);

int main()
{
    int length;
    char string[MAXSIZE];
    //���� ������ ������ 0 �������� ��������� ������
    while((length = getline(string)) != 0)
    {
        //���� ������ ������ 80 ��������, �� �������� ������
        if(length > 80)
        {
                printf("%s\n",string);
        }
    }
    return 0;
}

//��������� ������ �� ������� ����� ������ ��� ����� �����
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


//�������
