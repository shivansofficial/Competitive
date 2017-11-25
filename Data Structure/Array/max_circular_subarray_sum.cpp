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
int kadane(int arr[],int n)
{
  int max_so_far=0,max_end_here=0;
  for (int i = 0; i < n; i++)
  {
    max_end_here+=arr[i];
    if(max_end_here<0)
      max_end_here=0;
    if(max_so_far<max_end_here)
      max_so_far=max_end_here;
  }
  return max_so_far;
}
int maxCircularSum(int arr[],int n)
{
  int max_kadane=kadane(arr,n);
  int tot_sum=0;
  for (int i = 0; i < n; i++)
  {
    tot_sum+=arr[i];
    arr[i]=-arr[i];
  }
  int max_wrap=tot_sum+kadane(arr,n);
  return max(max_wrap,max_kadane);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a[] =  {11, 10, -20, 5, -3, -5, 8, -13, 10};
  int n = sizeof(a)/sizeof(a[0]);
  cout<<"Maximum circular sum is : "<<maxCircularSum(a, n)<<endl;
  return 0;
}
