#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
#define MAX 100007
int dp[MAX]={-1};
int solve( int a[],int n)
{ dp[0]=a[0];
  dp[1]=a[1];
  dp[2]=a[2];
  for (int i = 3; i <n; i++)
  {
    dp[i]=a[i]+min(dp[i-1],min(dp[i-2],dp[i-3]));
  }
  return min(dp[n-1],min(dp[n-2],dp[n-3]));

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int i,a[n];
  for  (i = 0; i <n; i++)
  {
    cin>>a[i];
  }
  if(n<=2) cout<<"0"<<endl;
  else cout<<solve(a,n)<<endl;


  return 0;
}
