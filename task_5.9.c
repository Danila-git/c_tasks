#include <stdio.h>

int day_of_year(int year,int month,int day);
void month_day(int year,int day, int *m, int *d);

//array of pointer
static int *day_tab[] =
{
   (int[]){0,31,28,31,30,31,30,31,31,30,31,30,31},
   (int[]){0,31,29,31,30,31,30,31,31,30,31,30,31}
} ;

int main()
{
    int year,day,month;
  printf("Enter year: ");
  scanf("%d",&year);
  printf("Enter day: ");
  scanf("%d",&day);
  month_day(year,day,&month,&day);
  printf("Month: %d and Day: %d",month,day);
}

int day_of_year(int year,int month,int day)
{
    if(month > 12 || month < 1 || day > 31 || day < 1)
    {
        printf("Not available data");
        return -1;
    }else{
    int leap = year % 4 == 0 && year % 100 != 0 && year % 400 == 0;

    for(int i = 1; i < month; i+=1)
    {
        //get address and then value
     day += *(day_tab[leap]+i);
    }
    return day;
    }
}

void month_day(int year,int day, int *m, int *d)
{
    if(day > 366 || day < 1)
    {
         printf("Not available data");
        return;
    }
    else
    {
    int i = 1;
    int leap = year % 4 == 0 && year % 100 != 0 && year % 400 == 0;
    for(;*(day_tab[leap]+i) < day; i++)
    {
        //get address and then value
        day -= *(day_tab[leap]+i);
    }
    *m = i;
    *d = day;
    }
}

//сделано