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
int maxSubarrayProduct(int arr[],int n)
{
  int r=arr[0];
  for (int i = 1,imax=r,imin=r; i < n; i++)
  {
    if(arr[i]<0)
      swap(imax,imin);
    imax=max(arr[i],imax*arr[i]);
    imin=min(arr[i],imin*arr[i]);
    r=max(r,imax);
  }
  return r;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {1, -2, -3, 0, 7, -8, -2};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"Maximum Sub array product is "<<maxSubarrayProduct(arr, n)<<endl;
  return 0;
}
