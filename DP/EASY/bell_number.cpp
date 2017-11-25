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
int bellNumber(int n)
{
  int dp[n+1][n+1];
  dp[0][0]=1;
  for (int i = 1; i <=n; i++)
  {
    dp[i][0]=dp[i-1][i-1];
    for (int j = 1; j <=i; j++)
    {
      dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
    }
  }
  return dp[n][0];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  for (int n=0; n<=5; n++)
  cout << "Bell Number " << n << " is "<< bellNumber(n) << endl;
  return 0;
}
