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
  node * left,* right;
}node;
node * new_node(int d)
{
  node * temp= new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
void inorder (node * root)
{
  node * curr=root;
  stack<node *>s;
  bool done =0;
  while(!done)
  {
    if(curr!=NULL)
    {
      s.push(curr);
      curr=curr->left;
    }
    else
    {
      if(!s.empty())
      {
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
      }
      else
        done=1;
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node *root = new_node(1);
  root->left        = new_node(2);
  root->right       = new_node(3);
  root->left->left  = new_node(4);
  root->left->right = new_node(5);
  inorder(root);
  return 0;
}
