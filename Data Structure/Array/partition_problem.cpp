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
bool findPartiion(int arr[],int n)
{
  int sum=0;
  int i,j;
  for (int i = 0; i < n; i++)
    sum+=arr[i];
  if(sum%2!=0)
    return false;
  bool part[sum/2+1][n+1];
  for ( i = 0; i <=n; i++)
    part[0][i]=true;
  for ( i = 1; i <=sum/2; i++)
    part[i][0]=false;
  for (i = 1; i <=sum/2; i++)
  {
    for (j = 1; j <=n; j++)
    {
      part[i][j]=part[i][j-1];
      if(i>=arr[j-1])
        part[i][j]=part[i][j-1]||part[i-arr[j-1]][j-1];
    }
  }
  return part[sum/2][n];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {3, 1, 1, 2, 2, 1,1,-1};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPartiion(arr, n) == true)
     cout<<"Can be divided into two subsets of equal sum"<<endl;
  else
     cout<<"Can not be divided into two subsets of equal sum"<<endl;
  return 0;
}
