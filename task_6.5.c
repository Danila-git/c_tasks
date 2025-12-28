#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist { 
struct nlist *next;
char *name; 
char *defn; 
};

static struct nlist *hashtab[HASHSIZE]; 

unsigned hash(char *s);
struct nlist *lookup(char *s);
char *str_dup(char *s);
struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);
int undef(char *name);

int main()
{
install("Anna","5");
install("Dima","8");
install("Georgy","12");
printf("%s\n",lookup("Dima")->defn);
printf("%d\n",undef("Dima"));
printf("%d\n",undef("Vityma"));
}

int undef(char *name)
{
    unsigned hashval;
    struct nlist *np, *prev = NULL;
    
    hashval = hash(name);

    for (np = hashtab[hashval]; np != NULL; prev = np, np = np->next) {
        if (strcmp(name, np->name) == 0) {
            
            if (prev == NULL) {
                hashtab[hashval] = np->next;
            } else {
                prev->next = np->next;
            }
            
            free(np->name);
            free(np->defn);
            free(np);
            
            return 1;
        }
    }

    return 0;
}

unsigned hash(char *s)
{
unsigned hashval;
for (hashval = 0; *s != '\0'; s++)
hashval = *s + 31 * hashval;
return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
struct nlist *np;
for (np = hashtab[hash(s)]; np != NULL; np = np->next)
{
if (strcmp(s, np->name) == 0)
{
return np; 
}
}
return NULL;
}

char *str_dup(char *s) 
{
char *p;
p = (char *) malloc(strlen(s)+1); 
if (p != NULL)
strcpy(p, s);
return p;
}

struct nlist *install(char *name, char *defn)
{
struct nlist *np;
unsigned hashval;
if ((np = lookup(name)) == NULL) { 
np = (struct nlist *) malloc(sizeof(*np));
if (np == NULL || (np->name = str_dup(name)) == NULL)
{
return NULL;
}
hashval = hash(name);
np->next = hashtab[hashval];
hashtab[hashval] = np;
} else 
free((void *) np->defn); 
if ((np->defn = str_dup(defn)) == NULL)
return NULL;
return np;
}
