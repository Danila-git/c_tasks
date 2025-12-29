# include <stdio.h>

#define MAXSIZE 100
#define swap(t,x,y)      t i = x;\
                         x = y;\
                         y = i;\
                        


int main()
{
    int first_arg,second_arg;
    printf("Enter first argument: ");
    scanf("%d",&first_arg);
    printf("Enter second argument: ");
    scanf("%d",&second_arg);
    swap(int,first_arg,second_arg);
    printf("Value of the first argument: %d\n",first_arg);
    printf("Value of the second argument: %d\n",second_arg);
}

//сделано