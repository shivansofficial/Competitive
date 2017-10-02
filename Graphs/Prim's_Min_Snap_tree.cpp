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
const int MAX = 1e4 + 5;
#define endl '\n'
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];
long long prim(int x)
{ priority_queue<PII,vector<PII>,greater<PII> > q;
  int y;
  PII p;
  long long minimumCost=0;
  q.push(make_pair(0,x));
  while(!q.empty())
  { p=q.top();
    q.pop();
    x=p.second;
    if(marked[x]==true) continue;
    minimumCost+=p.first;
    marked[x]=true;
    for (int i = 0; i <adj[x].size(); i++) {
    y=adj[x][i].second;
    if(marked[y]==false) q.push(adj[x][i]);
    }
  }
return minimumCost;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
   int nodes,edges,x,y;
   cin>>nodes>>edges;
   long long weight,minimumCost;
   for (int i = 0; i < edges; i++) {
    cin>>x>>y>>weight;
    adj[x].push_back(make_pair(weight,y));
    adj[y].push_back(make_pair(weight,x));
   }
minimumCost=prim(1);
cout<<minimumCost<<endl;
return 0;
}
