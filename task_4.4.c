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
double past_element;

int main()
{
    int type;
    double op_2;
    printf("\nEnter \"g\" to get past element and save it in stack \n");
        printf("Enter \"d\" to dublicate past element in stack \n");
        printf("Enter \"s\" to switch two past elements in stack \n");

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
            break;
    //added code
        //case to get past element from stack
        case 'g':
        past_element = pop();
            push(past_element);
            push(past_element);
            printf("Get past element and save it in stack: ");
        break;
        //case to double past element in stack
        case 'd':
        past_element = pop();
        push(past_element);
        push(past_element);
        push(past_element);
        printf("Dublicate past element in stack: ");
        break;
        //case to switch elements
        case 's':
        past_element = pop();
        double second_stack_element = pop();
        push(past_element);
        push(second_stack_element);
        push(past_element);
        printf("Switch two past elements in stack: %.8g and ",second_stack_element);
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
            if (next_ch != EOF)
                ungetch(next_ch);
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
        ungetch(ch);
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
