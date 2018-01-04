#include<vector>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define endl '\n'
int root(int x,vector<int>r)
{
  while(r[x]!=x)
  {
    r[x]=r[r[x]];
    x=r[x];
  }
  return x;
}
bool find(int x,int y,vector<int>r)
{
  if(root(x,r)==root(y,r))
    return true;
  return false;
}
void union1(int x,int y,vector<int>&r)
{
  int rx=root(x,r);
  int ry=root(y,r);
  r[x]=r[y];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int v,e;
    cin>>v>>e;
    int flag=0;
    vector<int> r(v);
    for(int i=0;i<v;i++)
      r[i]=i;
    for(int i=0;i<e;i++)
    {
      int x,y;
      cin>>x>>y;
      if(find(x,y,r))
        flag=1;
      else
        union1(x,y,r);
    }
    cout<<flag<<endl;
  }
  return 0;
}
