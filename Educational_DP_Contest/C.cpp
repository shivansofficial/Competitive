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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<vector<int> > a(n,vector<int>(3,0));
  vector<int> dp_curr(3,0);
  vector<int> dp_prev(3,0);

  for(int i=0; i<n; i++)
    for(int j=0; j<3; j++)
      cin>>a[i][j];

  for(int i=0; i<n; i++)
  {
      dp_curr[0] = max(dp_prev[1],dp_prev[2]) + a[i][0];
      dp_curr[1] = max(dp_prev[0],dp_prev[2]) + a[i][1];
      dp_curr[2] = max(dp_prev[0],dp_prev[1]) + a[i][2];

      dp_prev = dp_curr;
  }

  cout<<max(dp_curr[0],max(dp_curr[1], dp_curr[2]))<<endl;
  return 0;
}
