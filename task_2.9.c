#include <stdio.h>

int bitcount(int num);

int main()
{
    int num;
    scanf("%d",&num);
    printf("%d",bitcount(num));
}

int bitcount(int num)
{
    int b;
    for(b = 0; num != 0 ; b+=1)
    {
        /*������������ ������ ����� ������ 1,
        ���� ������ 1 ���������� ������� ����,
        � ���� ����� �� 1 �������� �����������*/
        num &= (num-1);
    }
    return b;
}

//c������
