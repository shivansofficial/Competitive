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
  char data;
  node* left,*right;
}node;
node * new_node(int d)
{
  node * temp = new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
int search(char in[],int ins,int ine,int val)
{
  int i;
  for (i = ins; i <=ine; i++)
  {
    if(in[i]==val)
      break;
  }
  return i;
}
node * buildTree(char in[],char pre[],int ins,int ine)
{
  if(ins>ine)
    return NULL;
  static int pre_index=0;
  node * tnode=new_node(pre[pre_index++]);
  int in_index=search(in,ins,ine,tnode->data);
  tnode->left=buildTree(in,pre,ins,in_index-1);
  tnode->right=buildTree(in,pre,in_index+1,ine);
  return tnode;
}
void print_inorder(node * root)
{
  if(root==NULL)
    return;
  print_inorder(root->left);
  cout<<root->data;
  print_inorder(root->right);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  node *root = buildTree(in, pre, 0, len - 1);
  print_inorder(root);
  cout<<endl;
  return 0;
}
