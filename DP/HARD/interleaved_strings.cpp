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
bool is_interleaved(string a,string b,string c)
{
  int m=a.size();
  int n=b.size();
  bool dp[m+1][n+1];
  memset(dp,false,sizeof(dp));
  if(m+n!=c.size())
    return false;
  for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
    {
      if(i==0 && j==0)
        dp[i][j]=true;

      else if(i==0 && b[j-1]==c[j-1])
        dp[i][j]=dp[i][j-1];

      else if(j==0 && a[i-1]==c[i-1])
        dp[i][j]=dp[i-1][j];

      else if(a[i-1]==c[i+j-1] && b[j-1]!=c[i+j-1])
        dp[i][j]=dp[i-1][j];

      else if(a[i-1]!=c[i+j-1] && b[j-1]==c[i+j-1])
        dp[i][j]=dp[i][j-1];

      else if(a[i-1]==c[i+j-1] && b[j-1]==c[i+j-1])
        dp[i][j]=dp[i-1][j]||dp[i][j-1];
    }
  }
  return dp[m][n];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a,b,c;
  cin>>a>>b>>c;
  is_interleaved(a,b,c)?cout<<"YES"<<endl:cout<<"NO"<<endl;
  return 0;
}
