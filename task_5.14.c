#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 500
#define STRLENGTHARRAY 500000
#define MAXLEN 100

char *lineptr[MAXLINES]; 

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right,int (*comp)(void *, void *),int sign);
int numcmp(char *, char *);
int getline(char str[],int max);

int main(int argc, char *argv[])
{
int nlines; 
int numeric = 0; 
char sign = 0;
    while (argc-- > 1 && argv[argc][0] == '-')
    {
        switch(argv[argc][1]){
         case'n':
         numeric = 1;
        break;
         case'r':
         sign = 1;
         break;
        default:
        printf("Enter -n or -r");
        break;
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
     my_qsort((void **) lineptr, 0, nlines-1,numeric ? (int (*)(void *, void *))numcmp : (int (*)(void *, void *))strcmp,sign);
     writelines(lineptr, nlines);
     return 0;
    } 
    else {
    printf("You enter too much strings\n");
    return 1;
    }
}

int readlines(char *lineptr[], int maxlines)
{
    char str_array[STRLENGTHARRAY];
    char *str_arr_pointer = str_array;
    int used_memory = 0;
    int len, nlines = 0;
    char  line[MAXLEN];

    while ((len = getline(line, MAXLEN)) > 0)
    {
    if (nlines >= maxlines)
    {
        return -1;
    }
    else {
    used_memory += len;
    if(used_memory >= STRLENGTHARRAY)
    {
        return -2;
    }
    line[len] = '\0'; 
    strcpy(str_arr_pointer, line);
    lineptr[nlines++] = str_arr_pointer;
    str_arr_pointer+=len + 1;
    }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    {
    printf( "%s\n", *lineptr++);
    }
}

int comparison(void *v[], int left,int i,int (*comp)(void *,void *),int sign)
{
    switch(sign)
    {
        case 1:
        return comp(v[i], v[left]) > 0;
        break;
        case 0:
        return comp(v[i], v[left]) < 0;
        break;
    }
}

void my_qsort(void *v[], int left, int right,int (*comp)(void *, void *),int sign)
{
int i, last;
void swap(void *v[], int, int);
    if (left >= right) 
    {
    return; 
    }
     swap(v, left, (left + right )/2);
     last = left;
    for (i = left+1; i <= right; i++)
    {
      if (comparison(v, left,i,comp,sign))
      {
      swap(v, ++last, i);
      }
    }
      swap(v, left, last);
      my_qsort(v, left, last-1, comp,sign);
      my_qsort(v, last+1, right, comp,sign);
    
}

int numcmp(char *s1, char *s2)
{
double v1, v2;
v1 = atof(s1);
v2 = atof(s2);
    if (v1 < v2)
        {
        return -1;
        }
         else if (v1 > v2){
          return 1;
         }
            else{
             return 0;
            }
}       

int getline(char str[],int max)
{
    char c;  
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < max)
    {
        str[i] = c;
        i += 1;
    }
    str[i] = '\0';
    return i;
}

void swap(void *v[], int i, int j)
{
void *temp;
temp = v[i];
v[i] = v[j];
v[j] = temp;
}

//сделано