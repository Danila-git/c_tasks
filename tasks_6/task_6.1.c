#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLENGTH 100
#define NKEYS (sizeof key_words / sizeof(struct key))
#define UGBUFSIZE 10

struct key {
    char *word;
    int amount;
} key_words[] = 
{
    {"\"_name\"",0},
    {"#define",0},
    {"//",0},
    {"_name",0},
    {"apple",0},
    {"bed",0},
    {"car",0},
    {"yellow",0},
};

int getword(char*,int);
int binsearch(char*,struct key*,int);

int main()
{
   int n;
   char word[MAXLENGTH];

   while(getword(word,MAXLENGTH) != EOF )
   {
    //add needed elements
    if(isalpha(word[0]) || word[0] == '#' || word[0] == '_' || word[0] == '/' || word[0] != '\"' || word[0] != '\'' )
    {
        if((n = binsearch(word,key_words,NKEYS)) >= 0)
        {
            key_words[n].amount += 1;
        }
    }
   }
   for(int i = 0;i < NKEYS;i+=1)
   {
    if(key_words[i].amount > 0)
    {
        printf("Word %s met int text %d timed\n",key_words[i].word,key_words[i].amount);
    }
   }
}


int binsearch(char* word,struct key* key_word, int keys_amount)
{
    int left = 0,right = keys_amount - 1, middle, condition;
     while(left <= right)
     {
        middle = (left+right)/2;
     if((condition = strcmp(word,key_word[middle].word)) > 0 )
     {
        left = middle + 1;
     }else if(condition < 0)
     {
        right = middle - 1;
     }else{
        return middle;
     }
    }
    return -1;

}

int getword (char *word, int lim)
{
int c, getch(void);
void ungetch(int);
char *w = word;
while (isspace(c = getch()))
;
if (c != EOF)
{
*w++ = c;
}
//add needed elements
if (!isalpha(c) && c != '#' && c != '_' && c != '/' && c != '\"' && c != '\'' ) {
*w = '\0';
return c;
}
for ( ; --lim > 0; w++)
{
//add needed elements
if (!isalnum(*w = getch()) && *w != '#' && *w != '_' && *w != '/' && *w != '\"' && *w != '\'') {
ungetch(*w);
break;
}
}
*w = '\0';
return word[0];
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