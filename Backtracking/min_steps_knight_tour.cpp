#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
#define endl '\n'
typedef struct node
{
  int a,b,dist;
}node;
bool is_safe(int n,int x,int y)
{
  return (x>=0 && y>=0 && x<n && y<n);
}
int min_steps_bfs(node s,int x,int y,int n)
{
  int xc[8]={1,-1,1,-1,2,-2,2,-2};
  int yc[8]={2,2,-2,-2,1,1,-1,-1};

  vector<vector<bool> >visited(n,vector<bool>(n,false));
  queue<node>q;
  q.push(s);
  visited[s.a][s.b]=true;
  while(!q.empty())
  {
    node temp=q.front();
    q.pop();
    visited[temp.a][temp.b]=true;

    if(temp.a==x && temp.b==y)
      return temp.dist;

        for(int i=0;i<8;i++)
        {
          int x_new=temp.a+xc[i];
          int y_new=temp.b+yc[i];
          if(is_safe(n,x_new,y_new) && !visited[x_new][y_new])
            {
              node d;
              d.a=x_new;
              d.b=y_new;
              d.dist=temp.dist+1;
              q.push(d);
            }
        }
    }
    return INT_MAX;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int xi,yi,xs,ys;
    cin>>xi>>yi>>xs>>ys;
    node s;
    s.a=xi-1;
    s.b=yi-1;
    s.dist=0;
    cout<<min_steps_bfs(s,xs-1,ys-1,n)<<endl;
  }
  return 0;
}
