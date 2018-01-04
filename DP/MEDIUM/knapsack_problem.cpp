#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'

int knapsack(int wt[],int W , int val[],int n)
{
  int dp[n+1][W+1];
  dp[0][0]=0;
  for (int i = 1; i <=n; i++)
  {
    dp[i][0]=0;
    for (int w = 1; w <=W; w++) {
      dp[0][w]=0;
      if(w<wt[i-1])
        dp[i][w]=dp[i-1][w];
      else
        dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]] , dp[i-1][w]);
    }
  }
      return dp[n][W];
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int val[] = {1, 2, 3};
   int wt[] = {4, 5, 1};
   int  W = 4;
   int n = sizeof(val)/sizeof(val[0]);
   cout<<knapsack(wt,W,val,n)<<endl;
   return 0;
}
