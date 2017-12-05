#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
using namespace std;
#define endl '\n'
typedef struct lnode
{
  int data;
  lnode * next;
}lnode;
typedef struct tnode
{
  int data;
  tnode *left,*right;
}tnode;
void append_list(lnode * head,int d)
{
  while(head->next!=NULL)
    head=head->next;
  lnode * temp =new lnode;
  head->next=temp;
  temp->next=NULL;
  temp->data=d;
}
tnode * new_node(int d)
{
  tnode * temp=new tnode;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
void print_list(lnode * head)
{
  while(head)
  {
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
void pre(tnode * root)
{
  if(!root)
    return;
  cout<<root->data<<" ";
  pre(root->left);
  pre(root->right);
}
tnode * sorted_list_to_bst(lnode ** head,int n)
{
  if(n<=0)
    return NULL;
  tnode * left_child=sorted_list_to_bst(head,n/2);
  tnode * root= new_node((*head)->data);
  root->left=left_child;
  (*head)=(*head)->next;
  root->right=sorted_list_to_bst(head,n-n/2-1);
  return root;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  lnode * head= new lnode;
  head->next = NULL;
  while(n--)
  {
    int x;
    cin>>x;
    append_list(head,x);
  }
  head = head->next;
  print_list(head);
  tnode * root=sorted_list_to_bst(&head,n);
  pre(root);
  cout<<endl;
  return 0;
}
