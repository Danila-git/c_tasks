#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 100
#define MAXLENGTH 200
#define STRARRSIZE 10000

int getline(char str[],int max);
void readlines(char str_array[], int* lines_counter);
void writelines(int n,int lines);

char* lineptr[MAXLINES];


int main(int argc, char* argv[])
{
    char str_array[STRARRSIZE];
    int lines_counter = 0, n = 10;
    if(argc > 1 && argv[1][0] == '-')
    {
        //check is first symbol after - is num
        if(isdigit(argv[1][1]))
        { 
            //read all first vector and change sign
            n = -atoi(argv[1]) ;
        }else{
            printf("Exception: you enter not number");
        }
    }
    
    readlines(str_array, &lines_counter);
    writelines(n,lines_counter);
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

void readlines(char str_array[], int* lines_counter)
{
    int len, used_memory;
    char *p,line[MAXLENGTH];

    while ((len = getline(line, MAXLENGTH)) > 0) {
        used_memory += len;
    if(STRARRSIZE - used_memory > 0)
    p = str_array;
    str_array += len+1;
    line[len] = '\0';
    strcpy(p,line);
    *(lineptr + *lines_counter) = p;
    (*lines_counter)++;
    }
}

void writelines(int n,int lines)
{
 int i = 0;
    while(n-- > 0 && lines-- > 0)
    {
        printf("%d %s\n",i+1,*(lineptr + i));
        i += 1;
    }
}

//сделано