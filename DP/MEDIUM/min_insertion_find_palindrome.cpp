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
int lcs(string a,string b)
{
  int n=a.size();
  int lcs[n+1][n+1];
  for (int i = 0; i <=n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if(i==0||j==0)
        lcs[i][j]=0;
      else if(a[i-1]==b[j-1])
        lcs[i][j]=lcs[i-1][j-1]+1;
      else
        lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
    }
  }
  return lcs[n][n];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  cin>>str;
  string rev=str;
  reverse(rev.begin(),rev.end());
  cout<< str.size()-lcs(str,rev)<<endl;
  return 0;
}
