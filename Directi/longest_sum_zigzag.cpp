#include<iostream>
#include<vector>
using namespace std;
int larg_zigzag(vector<vector<int> >v,int i,int j)
{
  int n=v.size();
  if(i==n-1)
    return v[i][j];

  int ans=0;
  for(int k=0;k<n;k++)
    if(k!=j)
      ans=max(ans,larg_zigzag(v,i+1,k));
  return ans+v[i][j];
}
int main()
{
  int n;
  cin>>n;
  vector<vector<int> > v(n,vector<int>(n));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>v[i][j];
  int ans=0;
  for(int j=0;j<n;j++)
    ans=max(ans,larg_zigzag(v,0,j));
  cout<<ans<<endl;
}
