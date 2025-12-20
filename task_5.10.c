#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>  
#include <string.h>

#define MAXOP 100 

void push(int val);
int pop(void);

int stack[MAXOP];
int sp = 0;  

int main(int argc, char *argv[]) {
    int i;
    int op2;
    
    if (argc < 2) {
        return 1;
    }
    
    for (i = 1; i < argc; i++) {
        char *arg = argv[i];

        if (isdigit(arg[0]) || (arg[0] == '-' && isdigit(arg[1]))) {
            push(atoi(arg));
        }
        else {
            switch (arg[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    if (strlen(arg) == 1) {
                        op2 = pop();
                        push(pop() - op2);
                    } else {
                        push(atoi(arg));
                    }
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0)
                        push(pop() / op2);
                    else {
                        return 1;
                    }
                    break;
                default:
                    return 1;
            }
        }
    }
    
    if (sp == 1) {
        printf("Result: %d\n", pop());
        return 0;
    } else {
        return 1;
    }
}

void push(int val) {
    if (sp < MAXOP) {
        stack[sp++] = val;
    } else {
        printf("EXCEPTION: stack is overflow\n");
        return -1;
    }
}

int pop(void) {
    if (sp > 0) {
        return stack[--sp];
    } else {
        printf("Exception: stack is emptyт\n");
        return -1;
    }
}

//сделано