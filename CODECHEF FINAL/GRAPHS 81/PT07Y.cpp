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
void dfs(int s,vi adj[],bool visited[])
{
  visited[s]=true;
  for (int i = 0; i < adj[s].size(); i++)
  {
    int curr=adj[s][i];
    if(!visited[curr])
      dfs(curr,adj,visited);
  }
}
bool iscycle(int s,vi adj[],bool visited[],int parent)
{
  visited[s]=true;
  for (int i = 0; i <adj[s].size(); i++)
  {
    int curr=adj[s][i];
    if(!visited[curr])
      {
        if(iscycle(curr,adj,visited,s))
          return true;
      }
    else if(curr!=parent)
        return true;
  }
return false;  
}
bool istree(vi adj[],bool visited[],int v)
{
  dfs(1,adj,visited);
  for (int i = 1; i <=v; i++)
  {
    if(!visited[i])
      return false;
  }
  for (int i = 0; i <=v; i++)
  {
    visited[i]=false;
  }
  if(iscycle(1,adj,visited,-1))
    return false;
return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int v,e;
  cin>>v>>e;
  vi adj[max];
  bool visited[max]={false};
  for (int i = 0; i < e; i++)
  {
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  istree(adj,visited,v)?cout<<"YES"<<endl:cout<<"NO"<<endl;
  return 0;
}
