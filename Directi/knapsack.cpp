#include<iostream>
#include<algorithm>
using namespace std;
/*int knapsack(int w,int wt[],int val[],int n)
{
  if(n==0||w==0)
    return 0;

  if(w<wt[n-1])
    return knapsack(w,wt,val,n-1);

    return max(val[n-1]+knapsack(w-wt[n-1],wt,val,n-1),knapsack(w,wt,val,n-1));
}*/
int knapsack(int w,int wt[],int val[],int n)
{
  int dp[n+1][w+1];
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=w;j++)
    {
      if(i==0||j==0)
        dp[i][j]=0;

      else if(wt[i-1]>j)
        dp[i][j]=dp[i-1][j];
      else
        dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][w]);
    }
  }
  return dp[n][w];
}
int main()
{
  int n,w;
  cin>>n>>w;
  int wt[n],val[n];
  for(int i=0;i<n;i++)
    cin>>wt[i];
  for(int i=0;i<n;i++)
      cin>>val[i];

  cout<<knapsack(w,wt,val,n)<<endl;
}
