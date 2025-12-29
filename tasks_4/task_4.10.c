#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXSTACKVAL 300
#define UGBUFSIZE 100

int getop(void);
void push(double num);
double pop(void);
int getch(void);
void ungetch(int ch);
int getline(char line[]);

char s[MAXOP];
int line_index = 0;
char line[MAXOP];
int main()
{
    int type;
    double op_2;
     getline(line);
    while((type = getop()) != EOF)
    {
        switch(type){
        case 0:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
        break;
        case '*':
            push(pop() * pop());
        break;
        case '-':
            op_2 = pop();
            push(pop() - op_2);
        break;
        case '/':
            op_2 = pop();
            if(op_2 != 0.0)
            {
                push(pop() / op_2);
            }else
            {
                printf("Exception: op_2 = 0");
            }
        break;
        case '%':
            op_2 = pop();
            if(op_2 != 0.0)
            {
                push((double)((int)pop() % (int)op_2));
            }else
            {
                printf("Exception: op2 = 0");
            }
            break;
        case '\n':
            printf("%.8g\n",pop());
            getline(line);
            break;
        default:
            printf("exception!!!");
        }
    }
}

int stack_pos = 0;
double stack[MAXSTACKVAL];

void push(double num)
{
    if(stack_pos < MAXSTACKVAL)
    {
        stack[stack_pos++] = num;
    }else
    {
        printf("error: stack overflow");
    }
}

double pop()
{
    if(stack_pos > 0)
    {
        return stack[--stack_pos];

    }else
    {
        printf("stack is empty\n");
        return 0.0;
    }
}

int getline(char s[])
{
    char c;
    int i = 0;
    while((c = getchar()) != EOF && c != '\n')
    {
            s[i] = c;
            i+=1;
    }
    s[i] = '\0';
}


int getop()
{
    char ch, i = 0;
    int next_ch;
    ch = line[line_index++];
    if (ch == '-')
    {
        next_ch = line[line_index++];
        if (isdigit(next_ch))
        {
            s[0] = '-';
            s[1] = next_ch;
            i = 1;
            ch = next_ch;
        }
        else
        {
            return '-';
        }
    }
    else if (!isdigit(ch) && ch != '.')
    {
        return ch;
    }

    if (isdigit(ch))
    {
        while (isdigit(s[++line_index] = ch = line[line_index++]))
            ;
    }

    if (ch == '.')
    {
        while (isdigit(s[++line_index] = ch = line[line_index++]))
            ;
    }

    s[line_index] = '\0';
    return 0;
}


