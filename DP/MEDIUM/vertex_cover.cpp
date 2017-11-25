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
//#define max 100007
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
  int vc;
  node * left,*right;
}node;
node * new_node(int d)
{
  node * temp=new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  temp->vc=0;
  return temp;
}
int v_cover(node * root)
{
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return 0;
  if(root->vc!=0)
    return root->vc;
  int size_incl=1+v_cover(root->left)+v_cover(root->right);

  int size_excl=0;
  if(root->left)
    size_excl+=1+v_cover(root->left->left)+v_cover(root->left->right);
  if(root->right)
    size_excl+=1+v_cover(root->right->left)+v_cover(root->right->right);
  root->vc=min(size_incl,size_excl);
  return root->vc;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node *root         = new_node(20);
  root->left                = new_node(8);
  root->left->left          = new_node(4);
  root->left->right         = new_node(12);
  root->left->right->left   = new_node(10);
  root->left->right->right  = new_node(14);
  root->right               = new_node(22);
  root->right->right        = new_node(25);
  cout<<"Smallest Vertex Cover :"<<v_cover(root)<<endl;
  return 0;
}
