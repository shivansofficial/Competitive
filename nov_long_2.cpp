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
  int t;
  cin>>t;
  while(t--)
  {
    int n,r;
    cin>>n>>r;
    int a[n];
    int max=-1;
    long long min=1000000007;
    for (int i = 0; i < n; i++)
      cin>>a[i];
    int flag=0;
    for (int i = 0; i < n; i++)
      if(a[i]>r)
        {
          max=a[i];
          break;
        }
    for (int i = 0; i < n; i++)
        if(a[i]<r)
        {
          min=a[i];
          break;
        }
    for (int i = 0; i < n; i++)
    {
      if(a[i]>r && a[i]<max)
        max=a[i];
      else if(a[i]>r && a[i]>max)
          flag=1;

      if(a[i]<r && a[i]>min)
        min=a[i];
      else if(a[i]<r && a[i]<min)
        flag=1;
    }
    flag==0?cout<<"YES"<<endl:cout<<"NO"<<endl;
  }
  return 0;
}