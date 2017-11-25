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
void zigZag(int arr[],int n)
{
  bool flag=true;
  for (int i = 0; i < n-1; i++)
  {
    if(flag)
    {
      if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    }
    else
    {
      if(arr[i]<arr[i+1])
        swap(arr[i],arr[i+1]);
    }
    flag=!flag;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int  arr[] = {4, 3, 7, 8, 6, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  zigZag(arr, n);
  for (int i=0; i<n; i++)
      cout << arr[i] << "  ";
  return 0;
}
