#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define endl '\n'
void solve(vector<int>a,int k,int i,int &ans,int &ans2)
{
  if(i>a.size()-1)
    return;
  solve(a,k,2*i+1,ans,ans2);
  if(++ans==k)
    ans2=a[i];
  solve(a,k,2*i+2,ans,ans2);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  int ans=0;
  int ans2=0;
  solve(a,k,0,ans,ans2);
  cout<<ans2<<endl;
}
