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
#define maxx 100007
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
int n;
const int N=1e5;
int t[2*N]={-1},dp[2*N]={0};
int h=ceil(log2(n));
int max(int a,int b)
{
  return a>b?a:b;
}
void apply(int p,int val)
{
  t[p]+=val;
  if(p<n)
    dp[p]+=val;
}

void push(int p)
{
  for (int s=h; s>0; --s)
  {
    int i=p>>s;
    if(dp[i]!=0)
    {
      apply(i<<1,dp[i]);
      apply(i<<1|1,dp[i]);
      dp[i]=0;
    }
  }
}

void build(int p)
{
  while(p>1)
  {
    p>>=1;
    t[p]=max(t[p<<1],t[p<<1|1])+dp[p];
  }
}
void inc(int l,int r,int val)
{
  l+=n,r+=n;
  int l0=l,r0=r;
  for (; l<r;l>>=1,r>>=1)
  {
    if(l&1)
      apply(l++,val);
    if(r&1)
      apply(--r,val);
  }
  build(l0);
  build(r0-1);
}

int query(int l,int r)
{
  l+=n,r+=n;
  push(l);
  push(r-1);
  int _max=-1e5;
  for (;l<r;l>>=1,r>>=1)
  {
    if(l&1)
      _max=max(_max,t[l++]);
    if(r&1)
      _max=max(_max,t[--r]);
  }
  return _max;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  for (int i = 0; i < n; i++)
    cin>>t[n+i];
  for (int i = 0; i <n; i++)
    build(n+i);
  cout<<query(1,6)<<endl;
  inc(1,6,5);
  cout<<query(0,3)<<endl;
  return 0;
}
