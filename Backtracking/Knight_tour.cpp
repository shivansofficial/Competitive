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
#define n 8
bool is_safe(int x,int y,int sol[n][n])
{
  return(x>=0 && x<n && y>=0 && y<n && sol[x][y]==-1);
}
bool solve_util(int x,int y,int move ,int sol[n][n],int xmove[n],int ymove[n])
{
  int next_x,next_y;
  if(move==n*n)
    return true;

  for (int i = 0; i < n; i++)
  {
    next_x=x+xmove[i];
    next_y=y+ymove[i];
    if(is_safe(next_x,next_y,sol))
    {
      sol[next_x][next_y]=move;
      if(solve_util(next_x,next_y,move+1,sol,xmove,ymove)==true)
        return true;
      else
        sol[next_x][next_y]=-1;
    }
  }
  return false;
}
void solveKT()
{
  int sol[n][n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      sol[i][j]=-1;

  int xmove[8]={  2, 1, -1, -2, -2, -1,  1,  2 };
  int ymove[8]={  1, 2,  2,  1, -1, -2, -2, -1 };

  sol[0][0]=0;

  if(solve_util(0,0,1,sol,xmove,ymove)==false)
      cout<<"No Solution"<<endl;
  else
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          cout<<sol[i][j]<<" ";
        }
        cout<<endl;
      }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  solveKT();
  return 0;
}
