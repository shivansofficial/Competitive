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
#define V 4
/*int count(vi adj[],int s,int d,int k)
{
  if(k==0 && s==d) return 1;
  if(k<=0) return 0;
  int path=0;
  for (int i = 0; i < adj[s].size(); i++)
  {
    int curr=adj[s][i];
    path+=count(adj,curr,d,k-1);
  }
  return path;
}*/
int count(int g[][V],int u,int v,int k)
{
  int dp[V][V][k+1];
  for (int e = 0; e <=k; e++)
  {
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        dp[i][j][e]=0;

        if(e == 0 && i==j)
          dp[i][j][e]=1;

        if( e==1 && g[i][j])
          dp[i][j][e]=1;

        if(e>1)
        {
            for (int a = 0; a < v; a++)
            {
              if(g[i][a])
                dp[i][j][e]+=dp[a][j][e-1];
            }
        }
      }
    }
  }
  return dp[u][v][k];
}
/*int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int v,e;
  cin>>v>>e;
  vi adj[max];
  for (int i = 0; i < e; i++)
  {
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
  }
  int s,d,k;
  cin>>s>>d>>k;
  cout<<count(adj,s,d,k)<<endl;
  return 0;
}*/
int main()
{
    int graph[V][V] = { {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << count(graph, u, v, k) << endl;
    return 0;
}
