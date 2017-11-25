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
  node * temp=new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
void bfs(node * root)
{
  if(root==NULL)
    return;
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    node * curr=q.front();
    cout<<curr->data<<" ";
    q.pop();
    if(curr->left!=NULL)
      q.push(curr->left);
    if(curr->right!=NULL)
      q.push(curr->right);
  }
  cout<<endl;
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
  root->right->right = new_node(6);
  bfs(root);
  return 0;
}
