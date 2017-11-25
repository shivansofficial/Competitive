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
//#define max 100007
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
int ceil_index(vector<int> &tail,int l,int r,int key)
{
  int m;
  while(r-l>1)
  {
     m=l+(r-l)/2;
    if(tail[m]>=key)
      r=m;
    else
      l=m;
  }
  return r;
}
int long_increasing_subseq(vector<int> &v)
{
  if(v.size()==0)
    return 0;
  vector<int>tail(v.size(),0);
  int len=1;
  tail[0]=v[0];
  for (int i = 1; i < v.size(); i++)
  {
    if(v[i]<tail[0])
      tail[0]=v[i];
    else if(v[i]>tail[len-1])
      tail[len++]=v[i];
    else
      tail[ceil_index(tail,-1,len-1,v[i])]=v[i];
  }
  return len;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin>>v[i];
  cout<<long_increasing_subseq(v)<<endl;
  return 0;
}
