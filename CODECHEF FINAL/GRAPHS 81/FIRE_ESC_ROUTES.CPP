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
typedef vector<ll> vl ;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vl > vvl ;
typedef vector<vd> vvd;
typedef vector<pii> vii;
typedef vector<string> vs;
#define endl '\n'
void dfs(ll s,vl adj[],bool visited[], ll &a)
{
  visited[s]=true;
  a++;
  for (ll i = 0; i <adj[s].size(); i++)
  {
    ll curr=adj[s][i];
    if(!visited[curr])
      {
        dfs(curr,adj,visited,a);
      }
  }
}

pair<ll,ll> ans(ll s,vl adj[], bool visited[],ll v)
{
  ll connected=0;
  ll n=1;
  for (ll i = 1; i <=v; i++)
  {
    if(!visited[i])
      {ll a=0;
       dfs(i,adj,visited,a);
       connected++;
       n*=a;
       n%=mod;
      }
  }

  return make_pair(connected,n);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    ll v,e;
    cin>>v>>e;
    vl adj[max];
    bool visited[max]={false};
    for (ll i = 0; i < e ; i++)
    {
      ll x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    pair<ll,ll> z=ans(1,adj,visited,v);
    cout<<z.first<<" "<<z.second<<endl;
  }
  return 0;
}
