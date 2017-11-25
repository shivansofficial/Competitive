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
void inorder(node * root)
{
  if(root==NULL)
    return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
node * create_node(int parent[],int i,node * created[],node * root)
{
  if(created[i]!=NULL)
    return root;
  created[i]=new_node(i);
  if(parent[i]==-1)
  {
    root=created[i];
    return root;
  }
  if(created[parent[i]]==NULL)
    root=create_node(parent,parent[i],created,root);
  node*p=created[parent[i]];
  if(p->left==NULL)
      p->left=created[i];
  else p->right=created[i];

  return root;  
}
node * createTree(int parent[],int n)
{
  node * created[n];
  for (int i = 0; i < n; i++)
    created[i]=NULL;
  node * root=NULL;
  for (int i = 0; i < n; i++)
    root=create_node(parent,i,created,root);
  return root;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
  int n = sizeof parent / sizeof parent[0];
  node *root = createTree(parent, n);
  cout << "Inorder Traversal of constructed tree\n";
  inorder(root);
  cout<<endl;
  return 0;
}
