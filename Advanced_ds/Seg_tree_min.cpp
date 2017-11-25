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
const int N=1e5;
int n;
int t[2*N];

void build()
{
  for (int i = n-1; i>0; i--)
    t[i]=min(t[i<<1],t[i<<1|1]);
}
int query(int l,int r)
{
  int _min=max;
  for (l+=n,r+=n;l<r;l>>=1,r>>=1)
  {
    if(l&1)
      _min=min(_min,t[l++]);
    if(r&1)
      _min=min(_min,t[--r]);
  }
  return _min;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  for (int i = 0; i <2*N; i++)
    t[i]=max;
  for (int i = 0; i < n; i++)
    cin>>t[n+i];
  build();
  for (int i = 1; i <= 2*n-1; i++)
    cout<<t[i]<<" ";
  cout<<endl;
  cout<<query(1,6)<<endl;
  return 0;
}
