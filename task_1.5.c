#include <stdio.h>

#define LOWER 0 //������ ������� ��������
#define UPPER 300 //������� ������� ��������
#define STEP 20 //��� ���������

int main()
{
    printf("Comparison table between Celsius (�C) and Fahrenheit (�F)\n Celsius\t Fahrenheit\n");
    for(float celcius = UPPER; celcius >= LOWER; celcius -= STEP)
    {
        printf("%3.0f\t\t %6.1f\n",celcius,celcius + 32.0 * (9.0/5.0));
    }
}
