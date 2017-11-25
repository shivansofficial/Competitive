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
string findLongestRepeatingSubSeq(string a)
{
  int n=a.size();
  int dp[n+1][n+1];
  for(int i=0;i<=n;i++)
    for (int j = 0; j<=n; j++)
      dp[i][i]=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(a[i-1]==a[j-1] && i!=j)
          dp[i][j]=1+dp[i-1][j-1];
        else
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }

    string res="";
    int i=n,j=n;
    while(i>0 && j>0)
    {
      if(dp[i][j]==dp[i-1][j-1]+1)
        {
          res=res+a[i-1];
          i--;
          j--;
        }
        else if(dp[i][j]==dp[i-1][j])
          i--;
        else
          j--;
    }
    reverse(res.begin(),res.end());

    return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string str = "AABEBCDD";
  cout << "The length of the largest subsequence that repeats itself is : "<< findLongestRepeatingSubSeq(str)<<endl;
  return 0;
}
