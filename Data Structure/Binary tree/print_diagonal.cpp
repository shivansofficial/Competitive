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
void diagonal(node * root)
{
  if(!root)
    return;
  map<int,vector<int> >m;
  int d=0;
  queue<pair<node*,int> > q;
  q.push(make_pair(root,0));
  while(!q.empty())
  {
    pair<node*,int> temp=q.front();
    q.pop();
    d=temp.second;
    node * curr=temp.first;
    m[d].push_back(curr->data);
    if(curr->left)
      q.push(make_pair(curr->left,d+1));
    if(curr->right)
        q.push(make_pair(curr->right,d));
  }
  map<int,vector<int> >:: iterator it;
  for (it=m.begin(); it!= m.end();it++)
  {
    for (int i = 0; i <it->second.size(); i++)
      cout<<it->second[i]<<" ";
    cout<<endl;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node* root = new_node(8);
  root->left = new_node(3);
  root->right = new_node(10);
  root->left->left = new_node(1);
  root->left->right = new_node(6);
  root->right->right = new_node(14);
  root->right->right->left = new_node(13);
  root->left->right->left = new_node(4);
  root->left->right->right = new_node(7);

  diagonal(root);
  return 0;
}
