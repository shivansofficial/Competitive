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
void bfs(int s,vi adj[],bool visited[],int dist[])
{
  queue<int> q;
  q.push(s);
  dist[s]=0;
  visited[s]=true;
  while(!q.empty())
  {
    int v=q.front();
    q.pop();
    for (int i = 0; i < adj[v].size(); i++)
    {
      int curr=adj[v][i];
      if(!visited[curr])
      {
        q.push(curr);
        dist[curr]=dist[v]+1;
        visited[curr]=true;
      }
    }
  }
}
int findcenter(vi adj[],bool visited[],int v)
{ int dist[max]={0};
  bfs(0,adj,visited,dist);
  int maxe=0,l=0;
  for (int i = 1; i < v; i++)
  {
    if(maxe<dist[i])
    {
      maxe=dist[i];
      l=i;
    }
  }
  for (int i = 0; i < v; i++)
  {
    dist[i]=0;
    visited[i]=false;
  }
  bfs(l,adj,visited,dist);
  for (int i = 0; i < v; i++)
  {
    if(maxe<dist[i])
      maxe=dist[i];
  }
  return (maxe%2==0)?maxe/2:maxe/2+1;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int v,e;
    cin>>v;
    vi adj[max];
    bool visited[max]={false};
    for (int i = 0; i <v-1; i++)
    {
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    cout<<findcenter(adj,visited,v)<<endl;
  }

  return 0;
}
