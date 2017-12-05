#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<map>

using namespace std;

typedef struct node{
  node * left;
  node * right;
  int data;
}node;
node * new_node(int d)
{
  node * temp= new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}

node * insert(node * root,int time,int k)
{
  if(root==NULL)
    return new_node(time);
  if(time-k<root->data && time+k > root->data)
    return root;

  if(time<root->data)
    root->left=insert(root->left,time,k);
  else
    root->right=insert(root->right,time,k);

  return root;
}
void pre(node * root)
{
  if(!root)
    return;
  cout<<root->data<<" ";
  pre(root->left);
  pre(root->right);
}
int main()
{
    node *root = NULL;
    root = insert(root, 7,4);
    root = insert(root, 15,4);
    root = insert(root, 30,4);
    root = insert(root, 17,4);
    root = insert(root, 35,4);
    root = insert(root, 45,4);

    pre(root);
    cout<<endl;
    return 0;
}
