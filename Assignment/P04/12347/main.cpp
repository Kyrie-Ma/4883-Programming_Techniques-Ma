#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct node {
  int value;
  node *left, *right;
  node() {
    left = NULL;
    right = NULL;
  }
  node(int temp) {
    value = temp;
    left = NULL;
    right = NULL;
  }
};
node *root = NULL;
void add(int temp);
void RecurPrint(node *current);

int main() {
  int treeValue;
  while(scanf("%d", &treeValue)!=EOF){
    add(treeValue);
  }
  RecurPrint(root);
}

void add(int temp) {
  if(root==NULL) {
    root = new node(temp);
    return;
  }
  node *current = root, *parent;
  while(current!=NULL) {
    parent = current;
    if(current->value<temp){
      current = current->right;
    }
    else if(current->value>temp){
      current = current->left;    
    }
    else 
      return;
  }
  if(parent->value<temp) {
    parent->right = new node(temp);
  }
  else 
    parent->left = new node(temp);
}

void RecurPrint(node *current) {
  if(current==NULL){
    return;
  }
  RecurPrint(current->left);
  RecurPrint(current->right);
  printf("%d\n", current->value);
}
