#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
int edit_string(string a, string b , int n , int m)
{ int dp[n+1][m+1];
  dp[0][0]=0;
 for (int i = 1; i<=n; i++) {
   dp[i][0]=i;
    for (int j =1 ; j <=m; j++) {
       dp[0][j]=j;
       if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
      else dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
    }
  }
  return dp[n][m];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string str1="sunday";
  string str2="saturday";
  cout<<edit_string(str1,str2,str1.length(),str2.length())<<endl;
  return 0;
}
