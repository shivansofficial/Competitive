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
#define max 10007
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
void dfs(int s,vi adj[],int parent[],int child[],bool seen[],int low[],int tym[])
{
  static int t=0;
  seen[s]=true;
  low[s]=tym[s]=++t;
  for (int i = 0; i <adj[s].size(); i++)
  {
    int curr=adj[s][i];
    if(curr==parent[s])
      continue;
    if(!seen[curr])
    {
      child[s]++;
      parent[curr]=s;
      dfs(curr,adj,parent,child,seen,low,tym);
      low[s]=min(low[s],low[curr]);
      if(low[curr]>tym[s])
        cout<<s<<" "<<curr<<endl;
    }
    else
    {
      low[s]=min(low[s],tym[curr]);
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int parent[max]={0};
  int child[max]={0};
  bool seen[max]={false};
  int low[max]={0};
  int tym[max]={0};
  int n,e;
  cin>>n>>e;
  vector<int> adj[max];
  for (int i = 0; i <e; i++)
  {
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  parent[1]=-1;
  dfs(1,adj,parent,child,seen,low,tym);
  return 0;
}
