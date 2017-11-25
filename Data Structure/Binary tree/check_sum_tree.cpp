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

/*int sum(node * root)
{
  if(root==NULL)
    return 0;

  return root->data+sum(root->left)+sum(root->right);
}
int isSumTree(node * root)
{
  int ls,rs;
  if(root==NULL||(root->left==NULL && root->right==NULL))
    return 1;
  ls=sum(root->left);
  rs=sum(root->right);

  if(root->data==ls+rs && isSumTree(root->left) && isSumTree(root->right))
      return 1;

  return 0;
}*/
int isleaf(node * root)
{
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return 1;
  return 0;
}
int isSumTree(node * root)
{
  int ls,rs;
  if(root==NULL||isleaf(root))
    return 1;
  if(isSumTree(root->left)&&isSumTree(root->right))
  {
    if(root->left==NULL)
      ls=0;
    else if(isleaf(root->left))
      ls=root->left->data;
    else
      ls=2*root->left->data;

    if(root->right == NULL)
      rs = 0;
    else if(isleaf(root->right))
      rs = root->right->data;
    else
      rs = 2*(root->right->data);

    return (root->data==ls+rs);
  }
  return 0;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node *root  = new_node(26);
  root->left         = new_node(10);
  root->right        = new_node(3);
  root->left->left   = new_node(4);
  root->left->right  = new_node(6);
  root->right->right = new_node(3);

  isSumTree(root)==1?cout<<"YES"<<endl:cout<<"NO"<<endl;
  return 0;
}
