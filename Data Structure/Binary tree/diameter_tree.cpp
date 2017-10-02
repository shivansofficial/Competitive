#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
typedef struct node
{ int data;
  node*left,*right;
}node;
node* newNode(int data)
{ node*temp=new node;
  temp->data=data;
  temp->left=temp->right=NULL;
  return temp;
}
int height(node*root)
{ if(!root)
    return 0;
  return 1+max(height(root->left),height(root->right));
}
int diameter(node*root)
{
  if(!root)
  return 0;
  int lheight=height(root->left);
  int rheight=height(root->right);
  int ldiameter=diameter(root->left);
  int rdiameter=diameter(root->right);
  return max(1+lheight+rheight,max(ldiameter,rdiameter)) ;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  cout<<diameter(root);
  return 0;
}
