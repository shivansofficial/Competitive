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
//long long int dp[1005][1005];
//int m,n;
//int max_dot_prod(int a[],int b[],int i,int j)
/*{
  if(i>=m||j>=n|| m-i < n-j)
    return 0;
  if(dp[i][j]==0)
      dp[i][j]=max(a[i]*b[j]+max_dot_prod(a,b,i+1,j+1),max_dot_prod(a,b,i+1,j));
  return dp[i][j];
}*/
int max_dot_prod(int a[],int b[],int m,int n)
{
  long long int dp[n+1][m+1];
  memset(dp,0,sizeof(dp));
  for (int i = 1; i <=n; i++)
  {
    for (int j = i; j <=m; j++)
    {
      dp[i][j]=max(dp[i-1][j-1]+a[j-1]*b[i-1],dp[i][j-1]);
    }
  }
  return dp[n][m];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int A[5] = {2, 3, 1, 7, 8};
  int B[3] = {3, 6, 7};
  //memset(dp,0,sizeof(dp));
  int m=5,n=3;
  cout<<max_dot_prod(A,B,5,3)<<endl;
  //cout<<max_dot_prod(A,B,0,0)<<endl;
  return 0;
}
