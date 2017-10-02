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
using namespace std;
#define endl '\n'
typedef struct node
{ node* child[26];
  bool isleaf;
}node;
node*newnode()
{
  node*temp=new node;
  int i;
  rep(i,26)
  {
    temp->child[i]=NULL;
    temp->isleaf=false;
  }
  return temp;
}
void insert(node*root,string s)
{
  int i;
  node*temp=root;
  rep(i,s.length())
  {
    int index=s[i]-'a';
    if(!temp->child[index])
      temp->child[index]=newnode();
    temp=temp->child[index];
  }
  temp->leaf=true;
}
bool search(node*root,string s)
{
  int i;
  node*temp=root;
  rep(i,s.length())
  {
    int index=s[i]-'a';
    if(!temp->child[index])
      return false;
    temp=temp->child[index];
  }
  return(temp!=NULL && temp->leaf);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q,i;
  cin>>n>>q;
  node*root=getnode();
  rep(i,n)
  {
    string s;
    cin>>s;
    insert(root,s);
  }
  rep(i,q)
  {
    string s;
    cin>>s;
    search(root,s)?cout<<"YES":cout<<"NO"<<endl;
  }
  return 0;
}
