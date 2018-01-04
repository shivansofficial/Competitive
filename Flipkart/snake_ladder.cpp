#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n=30;
    int x;
    cin>>x;
    map<int,int>m;
    for(int i=0;i<x;i++)
      {
        int s,d;
        cin>>s>>d;
        m[s]=d;
      }
    vector<bool>visited(31,false);
    visited[1]=true;
    queue<pair<int,int> >q;
    q.push(make_pair(1,0));

    while(!q.empty())
    {
      pair<int,int> temp;
      temp=q.front();
      q.pop();
      if(temp.first==n)
        {
          cout<<temp.second<<endl;
          break;
        }
      for(int i=temp.first+1;i<=temp.first+6 && i<=n;i++)
      {
        if(!visited[i])
        {
          visited[i]=true;
          int d;
          if(m.find(i)!=m.end())
            d=m[i];
          else
            d=i;
          q.push(make_pair(d,temp.second+1));
        }
      }
    }
  }
  return 0;
}
