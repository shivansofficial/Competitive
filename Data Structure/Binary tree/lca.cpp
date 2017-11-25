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
node * lca_util(node * root,int n1,int n2,bool &v1,bool &v2)
{
  if(root==NULL)
    return NULL;
  if(root->data==n1)
    {
      v1=true;
      return root;
    }
  if(root->data==n2)
  {
    v2=true;
    return root;
  }
  node * lca_left=lca_util(root->left,n1,n2,v1,v2);
  node * lca_right=lca_util(root->right,n1,n2,v1,v2);
  if(lca_left && lca_right)
    return root;
  return lca_left!=NULL?lca_left:lca_right;
}
bool find(node * root,int d)
{
  if(root==NULL)
    return false;
  if(root->data==d||find(root->left,d)||find(root->right,d))
    return true;
  return false;
}
node * find_lca(node * root,int n1,int n2)
{
  bool v1=false,v2=false;
  node * lca =lca_util(root,n1,n2,v1,v2);
  if((v1 && v2)||(v1 && find(lca,n2))||(v2 && find(lca,n1)))
    return lca;
  return NULL;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node *root = new_node(1);
  root->left = new_node(2);
  root->right = new_node(3);
  root->left->left = new_node(4);
  root->left->right = new_node(5);
  root->right->left = new_node(6);
  root->right->right = new_node(7);
  root->left->left->left = new_node(8);
  root->left->left->right = new_node(9);
  root->left->right->left = new_node(10);
  root->left->right->right = new_node(11);
  int n1,n2;
  cin>>n1>>n2;
  node * lca=find_lca(root,n1,n2);
  if(lca!=NULL)
    cout<<"LCA "<<n1<<","<<n2<<" :"<<lca->data<<endl;
  else
    cout<<"Not present"<<endl;
  return 0;
}
