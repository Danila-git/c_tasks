#include <stdio.h>

#define LOWER 0   // нижняя граница перевода
#define UPPER 300 // верхняя граница перевода
#define STEP 20   // шаг сравнения

int main()
{
    printf("Comparison table between Fahrenheit (°F) and Celsius (°C)\n");
    for (float fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * fahr - 32.0);
    }
    getchar();
}

// сделано
