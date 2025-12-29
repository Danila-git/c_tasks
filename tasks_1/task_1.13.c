#include <stdio.h>

int word_counter = 0;
int gisto_data[50];
void write_gistogramma(int gisto_data[]);

int main()
{
    int c;
    int symbol_count = 0;

  while((c = getchar()) != EOF)
  {
      if(c != ' ')
      {
        symbol_count += 1;
      }
      else
      {
        gisto_data[word_counter] = symbol_count;
        symbol_count = 0;
        word_counter += 1;
      }
  }
    gisto_data[word_counter] = symbol_count;
    word_counter += 1;
    write_gistogramma(gisto_data);
}

void write_gistogramma(int gisto_data[])
{
     for(int j = 0; j < word_counter; j += 1)
   {
       putchar('\n');
       for(int k = 0; k < gisto_data[j]; k += 1)
       {
           putchar('-');
       }
   }
}

