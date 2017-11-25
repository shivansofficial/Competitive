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
bool is_leaf(node * root)
{
  return (root->left==NULL && root->right ==NULL);
}
bool issame(node * root1,node * root2)
{
  stack<node *> s1,s2;
  s1.push(root1);
  s2.push(root2);
  while(!s1.empty()||!s2.empty())
  {
    if(s1.empty()||s2.empty())
      return false;
    node *a=s1.top();
    s1.pop();
    while(a!=NULL && !is_leaf(a))
    {
      if(a->right)
        s1.push(a->right);
      if(a->left)
          s1.push(a->left);
      a=s1.top();
      s1.pop();
    }
    node *b=s2.top();
    s2.pop();
    while(b!=NULL && !is_leaf(b))
    {
      if(b->right)
        s2.push(b->right);
      if(b->left)
          s2.push(b->left);
      b=s2.top();
      s2.pop();
    }
    if((!a && b)||(!a && b))
      return false;
    if(a && b)
    {
    if(a->data!=b->data)
        return false;
    }
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node *root1=new_node(1);
  root1->left = new_node(2);
  root1->right = new_node(0);
  root1->left->left = new_node(4);
  root1->left->right = new_node(6);
  root1->right->left = new_node(5);

  node *root2=new_node(1);
  root2->left = new_node(2);
  root2->right = new_node(3);
  root2->left->left = new_node(4);
  root2->left->right = new_node(5);
  root2->right->left = new_node(6);
  issame(root1,root2)?cout<<"Same"<<endl:cout<<"Not Same"<<endl;
  return 0;
}
