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
bool AP(int s,vi adj[],bool visited[],int parent[],int child[],int disc[],int low[])
{
 static int t=0;
 visited[s]=true;
 low[s]=disc[s]=++t;
 for (int i = 0; i < adj[s].size(); i++)
 {
   int curr=adj[s][i];
   if(curr==parent[s])
    return true;
   if(!visited[curr])
   {
     parent[curr]=s;
     child[s]++;
     if(AP(curr,adj,visited,parent,child,disc,low))
      return true;

     low[s]=min(low[s],low[curr]);

     if(parent[s]==-1 && child[s]>1)
      return true;
     if(parent[s]!=-1 && low[curr]>=disc[s])
      return true;
   }
   else
   {
     low[s]=min(low[s],disc[curr]);
   }
 }
 return false;
}

bool isBC(vi adj[],bool visited[],int parent[],int child[],int disc[],int low[],int v)
{ if(AP(0,adj,visited,parent,child,disc,low))
    return false;

  for (int i = 0; i<v; i++)
    {
      if(visited[i]==false)
      return false;
    }

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
  int parent[max]={-1};
  int child[max]={0};
  int low[max]={0};
  int disc[max]={0};
  for (int i = 0; i <e; i++)
  {
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  isBC(adj,visited,parent,child,disc,low,v)?cout<<"YES"<<endl:cout<<"NO"<<endl;
  return 0;
}
