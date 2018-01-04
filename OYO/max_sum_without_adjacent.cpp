#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
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
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
      cin>>a[i];

    int dp[n+1];
    dp[0]=0;
    dp[1]=a[0];
    for(int i=2;i<=n;i++)
     {
       dp[i]=max(dp[i-1],a[i-1]+dp[i-2]);
     }
     cout<<dp[n]<<endl;
  }
  return 0;
}
