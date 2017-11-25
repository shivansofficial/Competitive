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
node * constructTree(int pre[],int post[],int &pre_index,int l,int h,int n)
{
  if(pre_index>=n||l>h)
    return NULL;
  node * root=new_node(pre[pre_index++]);
  if(l==h)
    return root;
  int i;
  for ( i = l; i <=h; i++)
    if(pre[pre_index]==post[i])
        break;
  if(l<=h)
  {
    root->left=constructTree(pre,post,pre_index,l,i,n);
    root->right=constructTree(pre,post,pre_index,i+1,h,n);
  }
  return root;
}
void printInorder( node * root)
{
  if(root==NULL)
    return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
  int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
  int size = sizeof( pre ) / sizeof( pre[0] );
  int pre_index=0;
  node *root = constructTree(pre, post, pre_index,0,size-1,size);
  cout<<"Inorder traversal of the constructed tree" << endl;
  printInorder(root);
  cout<<endl;
  return 0;
}
