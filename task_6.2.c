//I realized this program like array of the roots of binary trees
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXXLENGTH 30

struct Secondary_node{
  char *data;
  struct Secondary_node* left_link;
  struct Secondary_node* right_link;
};
struct Node{
  int child_amount;
  char *data;
  struct Secondary_node* left_link;
  struct Secondary_node* right_link;
};


void arr_bin_search();
int getword(char *arr);
void read_tree(struct Secondary_node* child);
void read_arr_of_tree();
struct Secondary_node* set_child(struct Secondary_node *p, char* word, int *char_num);
int linear_search(char* word);

int n = 6;
struct Node* trees_arr[100];
int past_tree = -1;
int match_symb = 6;


int main(int argc, char* argv[])
{
  if (argc > 1) {
    n = atoi(argv[1]);
    }
    if (n <= 0) 
    {
      n = 6;
    }
  

  arr_bin_search();
  read_arr_of_tree();
}


int getword(char *arr)
{
  int c,i = 0;
 while((c = getchar()) != ' ' && c != '\t' && c != '\n' && c != EOF)
 {
  *(arr + i) = c;
  i+=1;
 }
 if(c == EOF)
 {
  return -1;
 }else
 {
 *(arr + i) = '\0';
 return i;
 }
}

void read_tree(struct Secondary_node* child)
{
  if (child != NULL) {
  read_tree(child->left_link);
  printf("%s\n",child->data);
  read_tree(child->right_link);
}
}

void read_arr_of_tree()
{
  for(int i = 0; i <= past_tree; i+=1)
  {
    if(trees_arr[i]->child_amount >= 1)
    {
      printf("Tree in the alphabetic order:\n");
      read_tree(trees_arr[i]->left_link);
      printf("%s\n",trees_arr[i]->data);
      read_tree(trees_arr[i]->right_link);
    }
    printf("\n\n");
  }
}

struct Secondary_node* set_child(struct Secondary_node *p, char* word, int *char_num)
{
 if(p == NULL)
 {
  int i;
  p = (struct Secondary_node*)malloc(sizeof(struct Secondary_node));
  p->data = (char*)malloc(*char_num + 1);
  p->left_link = p->right_link = NULL;
  for(i = 0; i < *char_num; i+= 1)
  {
    *(p->data + i) = *(word + i);
  }
  *(p->data + i) = '\0';
 }else if(strcmp(p->data, word) < 0)
 {
 p->right_link = set_child(p->right_link,word,char_num);
 }else if(strcmp(p->data, word) > 0)
 {
 p->left_link = set_child(p->left_link,word,char_num);
 }
 return p;
}

int linear_search(char* word)
{
  for(int i = 0; i <= past_tree; i++)
  {
    if(trees_arr[i] != NULL && strncmp(word, trees_arr[i]->data, n) == 0)
    {
      return i;
    }
  }
  return -1;
}


void arr_bin_search()
{
  char word[20];
  int char_num;

  while((char_num = getword(word)) != -1)
  {
    if(char_num - 1 > n)
    {
    int element;
    element = linear_search(word);
    
    if(element == -1)
    {
      int i;
      past_tree += 1;
      trees_arr[past_tree] = (struct Node*)malloc(sizeof(struct Node));
      trees_arr[past_tree]->data = (char*)malloc(char_num + 1);
      trees_arr[past_tree]->child_amount = 0;
      trees_arr[past_tree]->left_link = trees_arr[past_tree]->right_link = NULL;
      for(i = 0; i < char_num; i+=1)
      {
      *(trees_arr[past_tree]->data + i) =  *(word + i);
      }
      *(trees_arr[past_tree]->data + i) = '\0';
    }else
    {
      trees_arr[element]->child_amount += 1;
      if(strcmp(trees_arr[element]->data,word) > 0)
      {
       trees_arr[element]->left_link = set_child(trees_arr[element]->left_link,word,&char_num);
      }else if(strcmp(trees_arr[element]->data,word) < 0)
      {
       trees_arr[element]->right_link = set_child(trees_arr[element]->right_link,word,&char_num);
      }
    }
    }
  }
}

//сделано