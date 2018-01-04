#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
using namespace std;
#define endl '\n'
bool no_common(int x,int y,vector<pair<int,int> > p)
{
  bool flag=1;
  for(int i=0;i<p.size();i++)
    {
      if(x== p[i].first || x==p[i].second || y==p[i].first || y==p[i].second)
        flag=0;
    }
  return flag;
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
    vector<int>a(n);
    for(int i=0;i<n;i++)
      cin>>a[i];
    int x;
    cin>>x;
    int flag=0;
    map<int,vector<pair<int,int> > >hash;
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
        {
          if(hash.find(x-a[i]-a[j])!=hash.end())
          {
            if(no_common(i,j,hash[x-a[i]-a[j]]))
            {
             flag=1;
             break;
           }
          }
          hash[a[i]+a[j]].push_back(make_pair(i,j));
        }
    cout<<flag<<endl;
  }
  return 0;
}
