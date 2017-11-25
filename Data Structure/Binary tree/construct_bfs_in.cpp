#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mod 1000000007
#define max 100007
#define itr ::iterator it
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define repp(X,a,Y) for (int (X) = a;(X) < (Y);++(X))
#define set(a, b) memset(a, b, sizeof(a));
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vd> vvd;
typedef vector<pii> vii;
typedef vector<string> vs;
#define endl '\n'
typedef struct node
{
  int data;
  node* left,*right;
}node;
node * new_node(int d)
{
  node * temp = new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
int search(int in[],int ins,int ine,int val)
{
  int i;
  for (i = ins; i <=ine; i++)
    if(in[i]==val)
      return i;
  return -1;
}
int * extract(int in[],int level[],int m,int n)
{
  int * new_= new int[m];
  int j=0;
  for (int i = 0; i < n; i++)
  {
    if(search(in,0,m-1,level[i])!=-1)
      new_[j++]=level[i];
  }
  return new_;
}
node * buildTree(int in[],int level[],int ins,int ine,int n)
{
  if(ins>ine)
    return NULL;
  node * tnode=new_node(level[0]);
  if(ins==ine)
    return tnode;
  int in_index=search(in,ins,ine,tnode->data);
  int *llevel=extract(in,level,in_index,n);
  int *rlevel=extract(in+in_index+1,level,n-in_index-1,n);
  tnode->left=buildTree(in,llevel,ins,in_index-1,n);
  tnode->right=buildTree(in,rlevel,in_index+1,ine,n);
  delete [] llevel;
  delete [] rlevel;
  return tnode;
}
void print_inorder(node * root)
{
  if(root==NULL)
    return;
  print_inorder(root->left);
  cout<<root->data<<" ";
  print_inorder(root->right);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int in[]    = {4, 8, 10, 12, 14, 20, 22};
  int level[] = {20, 8, 22, 4, 12, 10, 14};
  int n = sizeof(in)/sizeof(in[0]);
  node *root = buildTree(in, level, 0, n - 1, n);
  print_inorder(root);
  cout<<endl;
  return 0;
}
