#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'
void sol(int i,vector<int>a,vector<vector<int> >&ans,int k,vector<int>&sub)
{
   if(k>0 && i>=a.size())
    return;
   if(k==0)
   {
     ans.push_back(sub);
     return ;
   }
   sub.push_back(a[i]);
   sol(i+1,a,ans,k-1,sub);
   sub.pop_back();
   sol(i+1,a,ans,k,sub);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  vector<vector<int> >ans;
  vector<int>sub;
  for(int i=1;i<=n;i++)
  {
    sol(0,a,ans,i,sub);
  }
  for(auto it=ans.begin();it!=ans.end();it++)
  {
    for(auto i=it->begin();i!=it->end();i++)
    {
      cout<<*i<<" ";
    }
    cout<<endl;
  }
  return 0;
}
