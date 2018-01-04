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
int fact(int n)
{
  return n<=1?1:n*fact(n-1);
}
int countsmall(string s,int low, int high )
{ int count=0;
  for (int i = low+1; i <=high; i++) {
    if(s[low]>s[i]) count++;
  }
  return count;
}
int findrank(string s)
{
  int length=s.size();
  int mul=fact(length);
  int rank=1;
  for(int i=0;i<length;i++)
  {
    mul/=(length-i);
    rank+=countsmall(s,i,length-1)*mul;
  }
  return rank;
}
int main()
{ ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s="string";
  cout<<findrank(s)<<endl;
  return 0;
}
