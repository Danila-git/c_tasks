#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("\n Range of signet char values from %d till %d",SCHAR_MIN,SCHAR_MAX);
    printf("\n  Range of signet short values from %d till %d",SHRT_MIN,SHRT_MAX);
    printf("\n   Range of signet int values from %d till %d",INT_MIN,INT_MAX);
    printf("\n    Range of signet long values from %d till %d",LONG_MIN,LONG_MAX);
    printf("\n Range of unsignet char values from 0 till %d",UCHAR_MAX);
    printf("\n  Range of unsignet short values from 0 till %u",USHRT_MAX);
    printf("\n   Range of unsignet int values from 0 till %u",UINT_MAX);
    printf("\n    Range of unsignet long values from 0 till %d",ULONG_MAX);
    printf("\n   Range of float values from %.*g till %.*g",FLT_MIN,FLT_MAX);
    printf("\n    Range of double values from %.*g till %.*g",DBL_MIN,DBL_MAX);
}
//сделано
