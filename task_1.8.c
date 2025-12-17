#include <stdio.h>

int main()
{
    int c,tab = 0,space = 0,new_line = 0;
    while((c = (getchar())) != '`')
    {
        if(c == '\t')
        {
            tab += 1;
        }else if(c == ' ')
        {
            space += 1;
        }else if(c == '\n')
        {
            new_line += 1;
        }
    }
    printf("\nAmount of tabs: %d\n Amount of spaces: %d\n Amount of new lines: %d\n",tab,space,new_line);
    getchar();
    return 0;
}

//�������
