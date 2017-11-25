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
int getMaxArea(int a[],int n)
{
  stack<int>s;
  int max_area=INT_MIN;
  int tp;
  int area_top;
  int i=0;
  while(i<n)
  {
    if(s.empty()||a[s.top()]<a[i])
      s.push(i++);
    else
    {
      tp=s.top();
      s.pop();
      area_top=a[tp]*(s.empty()?i:i-s.top()-1);
      if(max_area<area_top)
        max_area=area_top;
    }
  }
  while(!s.empty())
  {
    tp=s.top();
    s.pop();
    area_top=a[tp]*(s.empty()?i:i-s.top()-1);
    if(max_area<area_top)
      max_area=area_top;
  }
  return max_area;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int hist[] = {1,4,3,2,5,4};
  int n = sizeof(hist)/sizeof(hist[0]);
  cout << "Maximum area is " << getMaxArea(hist, n)<<endl;
  return 0;
}
