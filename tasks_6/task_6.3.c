//realized this task with link list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 40
struct Node{
  char* word;
  int*  num_of_strs;
  struct Node* next_node;
};

int str_counter = 0;
char *stop_words[] = {
    "the", "and", "or", "a", "an", "in", "on", "at", "to", "for",
    "of", "with", "by", "is", "are", "was", "were", "be", "been",
    NULL  
};

int getword(char *arr);
int is_not_stop_word(char *word);
struct Node* check_in_list(struct Node** node, char *word);
void create_table(struct Node** head);
void print_table(struct Node* node);

int main()
{
  struct Node *head = NULL;
  create_table(&head);  
  print_table(head);
  return 0;
}

int getword(char *arr)
{
  int c, i = 0;
  while((c = getchar()) != ' ' && c != '\t' && c != '\n' && c != EOF)
  {
    if(i < MAXSIZE - 1) 
    {
      arr[i++] = tolower(c);  
    }
  }
  
  if(c == EOF)
  {
    return -1;
  }
  else if(c == '\n')
  {
    str_counter += 1;
    arr[i] = '\0';
    return i;
  }
  else
  {
    arr[i] = '\0';
    return i;
  }
}

int is_not_stop_word(char *word)
{
  for(int i = 0; stop_words[i] != NULL; i+=1)  
  {
    if(strcmp(word,stop_words[i]) == 0)
    {
      return 0;
    }
  }
  return 1;
}

struct Node* check_in_list(struct Node** node, char *word)
{
  if(*node == NULL)  
  {
    *node = (struct Node*)malloc(sizeof(struct Node));
    (*node)->num_of_strs = (int*)calloc(30, sizeof(int));  
    (*node)->word = (char*)malloc(MAXSIZE);
    strcpy((*node)->word, word);  
    (*node)->next_node = NULL;
    
    (*node)->num_of_strs[0] = str_counter;
    return *node;
  }
  else if(strcmp((*node)->word, word) == 0)
  {
    int i = 0;
    while((*node)->num_of_strs[i] != 0 && i < 29)  
    {
      i+=1;
    }
    (*node)->num_of_strs[i] = str_counter;
    return *node;
  }
  else
  {
    return check_in_list(&(*node)->next_node, word); 
  }
}

void create_table(struct Node** head) 
{
  int c;
  char word[MAXSIZE];
  while((c = getword(word)) != -1)
  {
    if(c > 0 && is_not_stop_word(word))  
    {
      check_in_list(head, word);
    }
  }
}

void print_table(struct Node* node)
{
  if(node != NULL)  
  {
    print_table(node->next_node);
    printf("WORD: \"%s\" met at strings: ", node->word);
    int i = 0;
    while(node->num_of_strs[i] != 0 && i < 30) 
    {
      printf("%d ", node->num_of_strs[i]);
      i += 1;
    }
    printf("\n");
  }
}

//сделано