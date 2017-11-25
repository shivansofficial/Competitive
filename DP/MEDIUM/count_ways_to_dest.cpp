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
#define R 4
#define C 4
int countPaths(int arr[][C])
{
  if(arr[0][0]==-1)
    return 0;
  for (int i = 0; i < R; i++)
  {
    if(arr[i][0]==0)
      arr[i][0]=1;
    else
      break;
  }
  for (int j= 1; j<C; j++)
  {
    if(arr[0][j]==0)
      arr[0][j]=1;
    else
        break;
  }
  for (int i = 1; i < R; i++)
  {
    for (int j = 1; j < C; j++)
    {
      if(arr[i][j]==-1)
        continue;

      if(arr[i-1][j]>0)
        arr[i][j]+=arr[i-1][j];

      if(arr[i][j-1]>0)
        arr[i][j]+=arr[i][j-1];
    }
  }
  return (arr[R-1][C-1]>0)?arr[R-1][C-1]:0;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int maze[R][C] =  { {0,  0, 0, 0},
                       {0, -1, 0, 0},
                       {-1, 0, 0, 0},
                       {0,  0, 0, 0}};
  cout << countPaths(maze)<<endl;
  return 0;
}
