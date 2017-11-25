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
long long dp[20][180][2];
long long get_digits(long long x,vector<int> &digit)
{
    while(x)
    {
      digit.push_back(x%10);
      x/=10;
    }
}
long long digit_sum(int idx,int sum,int tight,vector<int>&digit)
{
  if(idx==-1)
    return sum;

  if(dp[idx][sum][tight]!=-1 && tight!=1)
    return dp[idx][sum][tight];

  long long ret=0;

  int k=tight?digit[idx]:9;

  for (int i = 0; i <=k; i++)
  {
    int new_tight=(digit[idx]==i)?tight:0;
    ret+=digit_sum(idx-1,sum+i,new_tight,digit);
  }
  if(!tight)
    dp[idx][sum][tight]=ret;
  return ret;
}
int rangeDigitSum(int a,int b)
{
  memset(dp,-1,sizeof(dp));
  vector<int> digita;
  get_digits(a-1,digita);

  long long ans1=digit_sum(digita.size()-1,0,1,digita);

  vector<int> digitb;
  get_digits(b,digitb);

  long long ans2=digit_sum(digitb.size()-1,0,1,digitb);

  return ans2-ans1;

}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long a = 123, b = 1024;
  cout << "digit sum for given range : "<< rangeDigitSum(a, b) << endl;
  return 0;
}
