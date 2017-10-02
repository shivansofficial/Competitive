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
int arr[max],size[max];
int root(int x)
{
  while(arr[x]!=x)
  {
    arr[x]=arr[arr[x]];
    x=arr[x];
  }
  return x;
}
bool find(int x,int y)
{
  if(root(x)==root(y))
    return true;
  return false;
}
void union1(int x,int y)
{
  int rootx=root(x);
  int rooty=root(y);
  if(size[rootx]<size[rooty])
  {
    arr[rootx]=arr[rooty];
    size[rooty]+=size[rootx];
  }
  else
  { arr[rooty]=arr[rootx];
    size[rootx]+=size[rooty];
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,e;
  cin>>n>>e;
  for (int i = 0; i < n ; i++)
  {
    arr[i]=i;
    size[i]=1;
  }
  bool flag=false;
  for (int i = 0; i < e; i++)
  {
    int x,y;
    cin>>x>>y;
    if(find(x,y))
       flag=true;
    else
      union1(x,y);
  }
  if(flag)
    cout<<"Cycle"<<endl;
  else
    cout<<"No Cycle"<<endl;
  return 0;
}
