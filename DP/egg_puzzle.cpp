#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
int dp[INT_MAX+1][INT_MAX+1]={-1}
int eggDrop(int n, int k)
{ if(k==1||k==0)
  return k;
  if(n==1)
  return k;
  if(dp[n][k]!=-1) return dp[n][k];
  for (int i = 1; i <=k; i++) {
     ans=1+max(eggDrop(n-1,i-1),eggDrop(n,k-i));
     if(ans<min)
     min=ans;
  }
  return min+1;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n = 2, k = 10;
  cout<<"Minimum number of trials in worst case with "<<n<<" eggs and "<<k<<" floors is"<< eggDrop(n, k)<<endl;
  return 0;
}
