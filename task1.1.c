#include <stdio.h>
#include <locale.h>

main()
{
    setlocale(LC_ALL, "Russian");
    printf("здравствуй, мир\n");
}
