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
#define n 4
#define INF INT_MAX
/*int minCost(int cost[][n],int s,int d)
{
  if(s==d||s+1==d)
    return cost[s][d];
  int min=cost[s][d];
  for (int i = s+1; i < d; i++)
  {
    int c=minCost(cost,s,i)+minCost(cost,i,d);
    if(c<min)
      min=c;
  }
  return min;
}*/
int minCost(int cost[][n])
{
  int dist[n];
  for (int i = 0; i < n; i++)
    dist[i]=INF;
  dist[0]=0;

  for (int i = 0; i <n; i++)
  {
    for (int j = i+1; j <n; j++)
    {
      if(dist[j]>dist[i]+cost[i][j])
        dist[j]=dist[i]+cost[i][j];
    }
  }
  return dist[n-1];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int cost[n][n]={ {0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}
                    };
  cout << "The Minimum cost to reach station "
          << n << " is " << minCost(cost)<<endl;
  return 0;
}
