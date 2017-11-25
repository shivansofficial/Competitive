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
#define max 100007
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
void gen_magic_sqr(int n)
{
  int magic_sqr[n][n];
  memset(magic_sqr,0,sizeof(magic_sqr));
  int i=n/2;
  int j=n-1;
  for(int num=1;num<=n*n;)
  {
    if(i==-1 && j==n)
    {
      j=n-2;
      i=0;
    }
    else
    {
      if(j==n)
        j=0;
      if(i<0)
        i=n-1;
    }
    if(magic_sqr[i][j])
    {
      i++;
      j-=2;
      continue;
    }
    else
      magic_sqr[i][j]=num++;

    j++,i--;
  }
  cout<<"Sum of every row : "<<n*(n*n+1)<<endl;
  for (int i = 0; i <n; i++)
  {
    for (int j = 0; j <n; j++)
    {
      cout<<magic_sqr[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  gen_magic_sqr(n);
  return 0;
}
