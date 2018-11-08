#ifndef tree_h
#define tree_h

typedef struct node{
  int key;
  char* value;
  struct node* left;
  struct node* right;
}node;

struct binaryTree{
  node* root;
  int size;
};

node* tree_new_node(int key, char* value);

void tree_as_list(node* root);

node* tree_set(node* node, int key, char* value);

char* tree_get(node* node, int key);

node* tree_find_lmc(node* node);

void tree_remove(node* node, int key);



#endif
