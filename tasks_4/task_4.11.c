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

char s[MAXOP];

int main()
{
    int type;
    double op_2;
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
                push((int)pop() % (int)op_2);
            }else
            {
                printf("Exception: op2 = 0");
            }
            break;
        case '\n':
            printf("%.8g\n",pop());
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


int getop()
{
    //static variable
    static bufp;
    int ch, i = 0;
    int next_ch;

    while((s[0] = ch = getch()) == ' ' || ch == '\t')
        ;
    s[1] = '\0';

    if (ch == '-')
    {
        next_ch = getch();
        if (isdigit(next_ch))
        {
            s[0] = '-';
            s[1] = next_ch;
            i = 1;
            ch = next_ch;
        }
        else
        {
            //exchange ungetch
            if (next_ch != EOF)
                if (bufp >= UGBUFSIZE)
                 {
                    printf ("ungetch: too much symbols\n");
                 }
                else
                {
                     buf[bufp++] = next_ch;
                }
            return '-';
        }
    }
    else if (!isdigit(ch) && ch != '.')
    {
        return ch;
    }

    if (isdigit(ch))
    {
        while (isdigit(s[++i] = ch = getch()))
            ;
    }

    if (ch == '.')
    {
        while (isdigit(s[++i] = ch = getch()))
            ;
    }

    s[i] = '\0';
    if (ch != EOF)
    {
        //exchange ungetch
        if (bufp >= UGBUFSIZE)
        {
        printf ("ungetch: too much symbols\n");
        }
        else
        {
        buf[bufp++] = ch;
        }
    }
    return 0;
}

char buf[UGBUFSIZE];
int bufp = 0;

int getch(void)
{
return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
if (bufp >= UGBUFSIZE)
{
printf ("ungetch: too much symbols\n");
}
else
{
buf[bufp++] = c;
}
}

//сделано