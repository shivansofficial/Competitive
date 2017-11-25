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
  {
    if(in[i]==val)
      break;
  }
  return i;
}
node * buildTree(int in[],int post[],int ins,int ine)
{
  if(ins>ine)
    return NULL;
  static int post_index=ine;
  node * tnode=new_node(post[post_index--]);
  if(ins==ine)
    return tnode;
  int in_index=search(in,ins,ine,tnode->data);
  tnode->right=buildTree(in,post,in_index+1,ine);
  tnode->left=buildTree(in,post,ins,in_index-1);
  return tnode;
}
void pre_order(node * root)
{
  if(root==NULL)
    return;
  cout<<root->data;
  pre_order(root->left);
  pre_order(root->right);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
  int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
  int n = sizeof(in)/sizeof(in[0]);
  node *root = buildTree(in, post, 0,n-1);
  pre_order(root);
  cout<<endl;
  return 0;
}
