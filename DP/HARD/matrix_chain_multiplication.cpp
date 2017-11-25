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
int matrix_chain_order(int p[],int n)
{
  int m[n][n];

  for (int i = 0; i < n; i++)
    m[i][i]=0;
  for(int l=2;l<n;l++)
  {
    for (int i = 0; i <n-l; i++)
    {
      int j=i+l;
      m[i][j]=INT_MAX;
      for (int k = i+1; k < j; k++)
      {
        int q = m[i][k]+m[k][j]+p[i]*p[k]*p[j];
        if(q<m[i][j])
          m[i][j]=q;
      }
    }
  }
  return m[0][n-1];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {30,35,15,5,10,20,25};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<matrix_chain_order(arr,n)<<endl;
  return 0;
}
