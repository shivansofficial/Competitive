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
bool is_subset_sum(int set[],int n,int sum)
{
  bool dp[n+1][sum+1];
  for (int i = 0; i <=n; i++)
    dp[i][0]=true;
  for (int i = 1; i <=sum; i++)
    dp[0][i]=false;
  for (int i = 1; i <=n; i++)
  {
    for(int j=1;j<=sum;j++)
    {
      if(set[i-1]>j)
        dp[i][j]=dp[i-1][j];
      if(j>=set[i-1])
        dp[i][j]=dp[i-1][j]||dp[i-1][j-set[i-1]];
    }
  }
  return dp[n][sum];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int set[] = {3, 34, 4, 12, 8};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if(is_subset_sum(set,n,sum))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
