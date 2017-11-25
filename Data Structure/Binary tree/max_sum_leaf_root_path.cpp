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
bool print_path(node * root,node * target_leaf)
{
  if(!root)
    return false;
  if(root==target_leaf||print_path(root->left,target_leaf)||print_path(root->right,target_leaf))
    {
      cout<<root->data<<" ";
      return true;
    }
    return false;
}
void get_target_leaf(node * root,int &max_sum,int curr_sum,node ** target_leaf)
{
  if(!root)
    return ;
  curr_sum+=root->data;
  if(root->left==NULL && root->right==NULL)
    {
      if(curr_sum>max_sum)
      {
        max_sum=curr_sum;
        *target_leaf=root;
      }
    }
  get_target_leaf(root->left,max_sum,curr_sum,target_leaf);
  get_target_leaf(root->right,max_sum,curr_sum,target_leaf);
}
int max_sum_path(node * root)
{
  if(!root)
    return 0;
  int max_sum=INT_MIN;
  node * target_leaf;
  get_target_leaf(root,max_sum,0,&target_leaf);
  print_path(root,target_leaf);
  cout<<endl;
  return max_sum;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node * root = new_node(10);
  root->left = new_node(-2);
  root->right = new_node(7);
  root->left->left = new_node(8);
  root->left->right = new_node(-4);
  cout<<"Following Path :"<<endl;
  int sum=max_sum_path(root);
  cout<<"Max Sum : "<<sum<<endl;
  return 0;
}
