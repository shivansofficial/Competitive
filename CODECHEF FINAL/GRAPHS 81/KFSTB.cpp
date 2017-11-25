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

void path(int s,int t,vi adj[],bool visited[],ll &count)
{
  visited[s]=true;
  if(s==t)
    {
    count++;
    count %= mod;
    }
  for (int i = 0; i < adj[s].size(); i++)
  {
    int curr=adj[s][i];
    if(!visited[curr])
      path(curr,t,adj,visited,count);
  }
  visited[s]=false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int d;
  cin>>d;
  while(d--)
  {
    int c,b,s,t;
    cin>>c>>b>>s>>t;
    bool visited[max]={false};
    vi adj[max];
    for (int i = 0; i < b; i++)
    {
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
    }
  ll count=0,flag=0;
  if(s==t)
    flag=1;
  path(s,t,adj,visited,count);
  flag?cout<<0<<endl:cout<<count  <<endl;
}
  return 0;
}
