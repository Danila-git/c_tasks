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
        /*уничтожается только самая правая 1,
        биты правее 1 становятся равными нулю,
        а биты слева от 1 остаются неизменными*/
        num &= (num-1);
    }
    return b;
}

//cделано
