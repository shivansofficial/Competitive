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
bool isBipartite(int s,vi adj[],int color[])
{
  color[s]=1;
  queue<int> q;
  q.push(s);
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    for (int i = 0; i <adj[u].size(); i++)
    {
      int curr=adj[u][i];
      if(color[curr]==-1)
      {
        color[curr]=1-color[u];
        q.push(curr);
      }
      else if(color[curr]==color[u])
        return false;
    }
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
  for (int i = 0; i <e; i++)
  {
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int color[max]={-1};

  for (int i = 1; i <=v; i++)
  {
    if(color[i]==-1)
    {
      if(!isBipartite(i,adj,color))
        {
          cout<<"Not Bipartite"<<endl;
          return 0;
        }
    }
  }
  cout<<"Bipartite"<<endl;
  return 0;
}
