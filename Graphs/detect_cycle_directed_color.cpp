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
enum Color {white,gray,black};
bool iscyclic(int s,vi adj[],int color[])
{
  color[s]=gray;
  for (int i = 0; i < adj[s].size(); i++)
  {
    int curr=adj[s][i];
    if(color[curr]==gray)
      return true;
    if(color[curr]==white && iscyclic(curr,adj,color))
      return true;
  }
  color[s]=black;
  return false;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int v,e;
  cin>>v>>e;
  vector<int>adj[max];
  for (int i = 0; i < e; i++)
  {
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
  }
  int color[max]={white};
  for (int i = 0; i <v; i++)
  {
    if(color[i]==white)
      {
        if(iscyclic(i,adj,color))
          {
            cout<<"Cyclic"<<endl;
            return 0;
          }
      }
  }
  cout<<"Non cyclic"<<endl;
  return 0;
}
