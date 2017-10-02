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
int level[10];
bool vis[10];
const int MAX = 1e4 + 5;
vector<int> adj[MAX];
void bfs(int s)
{ queue<int> q;
  q.push(s);
  level[s]=0;
  vis[s]=true;
  while(!q.empty())
  { int p=q.front();
    q.pop();
    for (int i = 0; i <p.size(); i++) {
      if(vis[v[p][i]]==false)
      { q.push(v[p][i]);
        level[v[p][i]]=level[p]+1;
        vis[v[p][i]]=true;
      }
    }
  }
}
