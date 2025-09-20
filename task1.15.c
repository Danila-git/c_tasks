#include <stdio.h>

#define LOWER 0 //������ ������� ��������
#define UPPER 300 //������� ������� ��������
#define STEP 20 //��� ���������

float transform(float celcius);

int main()
{
    printf("Comparison table between Celsius (�C) and Fahrenheit (�F)\n Celsius\t Fahrenheit\n");
    for(float celcius = LOWER; celcius <= UPPER; celcius += STEP)
    {
        printf("%3.0f\t\t %6.1f\n",celcius,transform(celcius));
    }
}

float transform(float celcius)
{
    return celcius + 32.0 * (9.0/5.0);
}

//�������
