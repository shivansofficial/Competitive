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
int height(node*root,int &ans)
{ if(!root)
    return 0;
  int left_height=height(root->left,ans);
  int right_height=height(root->right,ans);
  ans= max(ans,1+left_height+right_height);
  return 1+max(left_height,right_height);
}
int diameter(node*root)
{
  if(!root)
  return 0;
  int ans=-1;
  int height_tree=height(root,ans);
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  cout<<diameter(root)<<endl;
  return 0;
}
