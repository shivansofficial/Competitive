#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define endl '\n'
bool is_safe(int x,int y,vector<vector<int> > a)
{
  return (x>=0 && x<a.size() && y>=0 && y<a[0].size() && a[x][y]);
}
void dfs(vector<vector<int> > a,vector<vector<bool> >&vis,int x,int y)
{
  vis[x][y]=true;
  for(int i=-1;i<2;i++)
    for(int j=-1;j<2;j++)
      {
        if(i==0 && j==0)
          continue;
        if(is_safe(x+i,y+j,a) && !vis[x+i][y+j])
          dfs(a,vis,x+i,y+j);
      }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>a[i][j];

    vector<vector<bool> >vis(n,vector<bool> (m,false));
    int count=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if( a[i][j] && !vis[i][j])
          {
            dfs(a,vis,i,j);
            count++;
          }

    cout<<count<<endl;
  }
  return 0;
}
