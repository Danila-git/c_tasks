#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSIZE 30
#define INITIAL_CAPACITY 20

struct Element {
    int popularity;
    char word[MAXSIZE];
};

struct Element* e_array = NULL;
int past = -1;
int capacity = 0;

int getword(char *arr, int max_len) {
    int c, i = 0;
    
    while ((c = getchar()) != EOF && isspace(c));
    
    if (c == EOF) return -1;
    
    do {
        if (i < max_len - 1) arr[i++] = tolower(c);
        c = getchar();
    } while (c != EOF && !isspace(c));
    
    arr[i] = '\0';
    return i;
}

void read_stream() {
    char word[MAXSIZE];
    int length;
    
    if (e_array == NULL) {
        capacity = INITIAL_CAPACITY;
        e_array = malloc(capacity * sizeof(struct Element));
    }
    
    while ((length = getword(word, MAXSIZE)) != -1) {
        if (length == 0) continue;   
        int found = 0;
        for (int i = 0; i <= past; i++) {
            if (strcmp(e_array[i].word, word) == 0) {
                e_array[i].popularity++;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            if (past + 1 >= capacity) {
                capacity *= 2;
                struct Element* new_arr = realloc(e_array, capacity * sizeof(struct Element));
                if (new_arr == NULL) return;
                e_array = new_arr;
            }
            
            past++;
            strncpy(e_array[past].word, word, MAXSIZE - 1);
            e_array[past].word[MAXSIZE - 1] = '\0';
            e_array[past].popularity = 1;
        }
    }
}

void arr_sort() {
    for (int i = 0; i <= past; i++) {
        for (int j = i + 1; j <= past; j++) {
            if (e_array[i].popularity > e_array[j].popularity) {
                struct Element temp = e_array[i];
                e_array[i] = e_array[j];
                e_array[j] = temp;
            }
        }
    }
}

void write_stream() {
    for (int i = 0; i <= past; i++) {
        printf("%d %s\n", e_array[i].popularity, e_array[i].word);
    }
}

int main() {
    read_stream();
    arr_sort();
    write_stream();
    
    if (e_array != NULL) free(e_array);
    return 0;
}

//сделано