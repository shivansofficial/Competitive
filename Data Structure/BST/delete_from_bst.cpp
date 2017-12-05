#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<map>

using namespace std;

typedef struct node{
  struct node * left;
  struct node * right;
  int val;
}node;

node * get_min_value(ndoe * root)
{
  node * curr = root;
  while(curr->left!=NULL)
    curr = curr->left;
  return curr;
}
node * _delete(node * root,int data)
{
  if(root==NULL)
    return root;
  if(data > root->val)
    root->right = _delete(root->right,data);
  if(data < root->val)
    root->left = _delete(root->left,data);
  if(data == root->val)
  {
    if(root->left==NULL)
    {
      node * temp = root->right;
      free(root);
      return temp;
    }
    else
      if(root->right==NULL)
    {
      node * temp = root->left;
      free(root);
      return temp;
    }
    node * temp  = get_min_value(root->right);
    root->key  = temp->key;
    root->right = _delete(root->right,temp->key);
  }
  return root;
}
int main()
{
  struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    _delete(80);
  return 0;
}
