#include <stdio.h>

int word_counter = 0;
int types_of_symbols[3] = {0,0,0};

void write_gistogramma(int types_of_symbols[]);

int main()
{
    int c;
    int symbol_count = 0;

  while((c = getchar()) != EOF)
  {
      if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
      {
        types_of_symbols[0] += 1;
      }
      else if(c >= '0' && c <= '9')
      {
        types_of_symbols[1] += 1;
      }else
      {
        types_of_symbols[2] += 1;
      }
  }
    write_gistogramma(types_of_symbols);
}

void write_gistogramma(int types_of_symbols[])
{
     for(int j = 0; j <= 2; j += 1)
   {
       putchar('\n');
       switch (j)
       {
       case 0:
        printf("Amount of letters: ");
        break;
        case 1:
        printf("Amount of numbers: ");
        break;
        case 2:
        printf("Other symbols:     ");
        break;
       }
       for(int k = 0; k < types_of_symbols[j]; k += 1)
       {
           putchar('-');
       }
   }
}


//сделано
