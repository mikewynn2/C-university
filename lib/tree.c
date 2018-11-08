#include <stdio.h>
#include <stdlib.h>

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

struct node* tree_new_node(int key, char* value) 
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->key = key;
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void tree_as_list(struct node *root)
{
    if (root != NULL)
    {
        tree_as_list(root->left);
        printf("%d: %s \n", root->key, root->value);
        if (root->left != NULL) {
          printf("Left: %d\n", root->left->key);
        }
        if (root->right != NULL) {
          printf("Right: %d\n", root->right->key);
        }
        tree_as_list(root->right);
    }
}

struct node* tree_set(struct node* node, int key, char* value)
{
  if(node == NULL){
    return tree_new_node(key, value);
  }
  if(key < node->key){
    node->left = tree_set(node->left, key, value);
  }
  else if(key > node->key){
    node->right = tree_set(node->right, key, value);
  }
  else {
    node->value = value;
  }
  
  return node;

}

char* tree_get(struct node* node, int key)
{
  if (node->key == key) {
    return node->value;
  }

  if (node->left != NULL) {
    return tree_get(node->left, key);
  }

  if (node->right != NULL) {
    return tree_get(node->right, key);
  }

  return NULL;
}

struct node* tree_find_lmc(struct node* node)
{
  if (node->left->left != NULL) {
    return tree_find_lmc(node->left);
  }


  struct node* nodeToReturn = node->left;
  node->left = node->left->right;
  return nodeToReturn;
}


void tree_remove(struct node* node, int key)
{
  struct node* foundNode = NULL;
  int isLeft = 0;

  if (node->left != NULL) {
    if (node->left->key == key) { 
      foundNode = node->left;
      isLeft = 1;
    } 
    else if (node->left->key > key){
      return tree_remove(node->left, key);
    }
  } 

  if (foundNode == NULL && node->right != NULL) {
    if (node->right->key == key) { 
      foundNode = node->right;

    } 
    else if (node->right->key < key){
      return tree_remove(node->right, key);
    }
  } 

  if (foundNode != NULL) {
    if (foundNode->right == NULL) {
      if (isLeft) {
        node->left = foundNode->left;
      }
      else {
        node->right = foundNode->right;
      }
    }
  }
  else if (foundNode->right->left == NULL) {
    if (isLeft) {
      node->left = foundNode->right;
      node->left->left = foundNode->left;
    }
    else {
      node->right = foundNode->right;
      node->right->left = foundNode->left;
    }
  }
  else {
    struct node* replacement = tree_find_lmc(foundNode->right);
    if (isLeft) {
      node->left = replacement;
    }
    else {
      node->right = replacement;
    }

    replacement->left = foundNode->left;
    replacement->right = foundNode->right;
  }
}


