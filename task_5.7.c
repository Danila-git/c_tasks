#include <stdio.h>
#include <string.h>

 #define MAXLINES 5000 
 #define MAXSIZE 10000

 char *lineptr[MAXLINES]; 

 int readlines(char *lineptr[], int nlines,char *str_array,int arr_size);
 void writelines(char *lineptr[], int nlines);
 void qsort(char *lineptr[], int left, int right);

int main()
{
int nlines; 
//against alloc add array for strings
char str_array[MAXSIZE];
    if ((nlines = readlines(lineptr, MAXLINES, str_array,MAXSIZE)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
    }
    else {
    printf("ошибка: слишком много строк\n");
    return 1;
    }
}

#define MAXLEN 1000 

int getline(char *, int);

int readlines(char *lineptr[], int maxlines, char *str_array,int arr_size)
{
    int used_memory = 0;
    int len, nlines = 0;
    char *p, line[MAXLEN];

    while ((len = getline(line, MAXLEN)) > 0)
    {
    if (nlines >= maxlines)
    {
        return -1;
    }
    else {
    //check overflow
    used_memory += len;
    if(used_memory >= arr_size)
    {
        return -2;
    }
    //stay pointer
    p = str_array;
    //transfer pointer to the length of the string
    str_array+=len;
    line[len-1] = '\0'; 
    strcpy(p, line);
    lineptr[nlines++] = p;
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

void qsort(char *v[], int left, int right)
{
int i, last;

    void swap(char *v[], int i, int j);

     if (left >= right)
     {
        return; 
     }
    swap(v, left, (left+ right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
    {
    if (strcmp(v[i], v[left]) < 0)
    {
    swap(v, ++last, i);
    }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


void swap(char *v[], int i, int j)
{
char *temp;
temp = v[i];
v[i] = v[j];
v[j] = temp;
}

int getline(char* str,int max)
{
    char c;  
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < max)
    {
        *(str+i) = c;
        i += 1;
    }
    *(str+i) = '\0';
    return i;
}

//сделано