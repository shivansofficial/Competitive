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
int getNthUglyNo(int n)
{
  int ugly[n];
  int i2=0,i3=0,i5=0;
  int next_multiple_2=2,next_multiple_3=3,next_multiple_5=5;
  int next_ugly_no=1;
  ugly[0]=1;
  for (int i = 1; i <n; i++)
  {
    next_ugly_no=min(next_multiple_2,min(next_multiple_3,next_multiple_5));
    ugly[i]=next_ugly_no;
    if(next_ugly_no==next_multiple_2)
      next_multiple_2=ugly[++i2]*2;
    if(next_ugly_no==next_multiple_3)
        next_multiple_3=ugly[++i3]*3;
    if(next_ugly_no==next_multiple_5)
        next_multiple_5=ugly[++i5]*5;
  }
  return next_ugly_no;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n = 150;
  cout << getNthUglyNo(n)<<endl;
  return 0;
}
