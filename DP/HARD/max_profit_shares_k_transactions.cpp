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
int maxProfit(int p[],int n,int k)
{
  int profit[k+1][n];
  for (int i = 0; i <n; i++)
    profit[0][i]=0;
  for (int i = 0; i <=k; i++)
    profit[i][0]=0;
  for (int i = 1; i <=k; i++)
  {
    for (int j= 1; j<n; j++)
    {
      int max_so_far=INT_MIN;
      for (int m = 0; m < j; m++)
      {
        max_so_far=max(max_so_far,p[j]-p[m]+profit[i-1][m]);
      }
      profit[i][j]=max(profit[i][j-1],max_so_far);
    }
  }
  return profit[k][n-1];
}
/*int maxProfit(int p[],int n,int k)
{
  int profit[k+1][n];
  for (int i = 0; i <n; i++)
    profit[0][i]=0;
  for (int i = 0; i <=k; i++)
    profit[i][0]=0;
    for (int i = 1; i <=k; i++)
    {
      int prev_diff=INT_MIN;
      for (int j= 1; j<n; j++)
      {
        prev_diff=max(prev_diff,profit[i-1][j-1]-p[j-1]);
        profit[i][j]=max(profit[i][j-1],p[j]+prev_diff);
      }
    }
      return profit[k][n-1];
}*/
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int k = 3;
  int price[] = {12, 14, 17, 10, 14, 13, 12, 15};
  int  n = sizeof(price)/ sizeof(price[0]);

  cout << "Maximum profit is: "<< maxProfit(price, n, k)<<endl;
  return 0;
}
