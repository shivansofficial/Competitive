#include<bits/stdc++.h>
using namespace std;
# define max 100001
vector<int> city[max];
long double ans(int v,int p)
{ int count=0;
  long double length=0.0;
  for(auto& u:city[v])
  { if(u==p) continue;
    length+=(1+ans(u,v));
    count++;
    }
  return count==0?0.0:length/count;
}
int main()
{ int n;
  cin>>n;
  for (int i = 0; i <n-1; i++)
  {
  int x,y;
  cin>>x>>y;
  city[x].push_back(y);
  city[y].push_back(x);
  }
  cout<<std::setprecision(15)<<ans(1,0)<<endl;
  return 0;
}
