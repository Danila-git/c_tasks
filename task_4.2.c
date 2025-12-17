#include <stdio.h>
#include <math.h>
#include <ctype.h>

double ATOF(char s[]);

int main()
{
    char s[100] = "-0.0001e-12";
   printf("result:%.18f", ATOF(s));
}

double ATOF (char s[])
{
double val, power = 1.0;
int i, sign;
for (i = 0; isspace(s[i]); i++)
;
sign = (s[i] == '-') ? -1 : 1;
if (s[i] == '+' || s[i] == '-')
{
 i+=1;
}
for (val = 0.0; isdigit (s[i]); i++)
{
val = 10.0 * val + (s[i] - '0');
}
    if (s[i] =='.')
    {
        i+=1;
    }
for (power = 1.0; isdigit(s[i]); i++) {
val = 10.0 * val + (s[i] - '0');
power *= 10.0;
}
//if num with e-..., then
    if(s[i] == 'e' && s[++i] == '-')
    {
    i+=1;
    int exponent = 0;
    while(isdigit(s[i]))
    {
        exponent = 10 * exponent + (s[i] - '0');
        i+=1;
    }
    power *= (double)pow(10.0,exponent);
    }
return sign * val / power;
}

//сделано
