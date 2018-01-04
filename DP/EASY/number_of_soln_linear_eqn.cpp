#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
#define endl '\n'
int count(vector<int>c,int rhs)
{
  int dp[rhs+1];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  for(int i=0;i<c.size();i++)
  {
    for(int j=c[i];j<=rhs;j++)
    {
      dp[j]+=dp[j-c[i]];
    }
  }
  return dp[rhs];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int>c(n);
  int rhs;
  for(int i=0;i<n;i++)
    cin>>c[i];
  cin>>rhs;
  cout<<count(c,rhs)<<endl;
  return 0;
}
