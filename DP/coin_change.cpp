#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
int count( int s[], int m, int n )
{ int dp[n+1];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  for (int i = 0; i <m; i++)
  { for (int j =s[i] ; j<=n; j++)
    {  dp[j]+=dp[j-s[i]];}
  }
return dp[n];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {1, 2, 3};
  int m = sizeof(arr)/sizeof(arr[0]);
  int n = 4;
  cout<<count(arr, m, n);
  return 0;
}
