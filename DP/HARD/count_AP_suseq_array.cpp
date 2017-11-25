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
int numofAP(int arr[],int n)
{
  int max_arr=INT_MIN,min_arr=INT_MAX,dp[n],sum[max];

  for (size_t i = 0; i < n; i++)
  {
    if(arr[i]>max_arr)
      max_arr=arr[i];
    if(arr[i]<min_arr)
      min_arr=arr[i];
  }
  int ans=n+1;
    for (int d = min_arr-max_arr; d <= max_arr-min_arr; d++)
    {
      memset(sum,0,sizeof(sum));
      for (int i = 0; i < n; i++)
      {
        dp[i]=1;
        if(arr[i]-d>0 && arr[i]-d<=1000000)
          dp[i]+=sum[arr[i]-d];
        ans+=dp[i]-1;
        sum[arr[i]]+=dp[i];
      }
    }
    return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = { 1, 2, 3 };
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << numofAP(arr, n) << endl;

  return 0;
}
