#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
int lis(int a[],int n)
{ int *dp,max=0;
  dp=(int*)malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++) {
  dp[i]=1;
  }
  for (int i = 1; i < n; i++) {
   for (int j = 0; j <i; j++) {
     if(a[i]>a[j] && dp[i]<dp[j]+1)
       dp[i]=dp[j]+1;
   }
  }
 for (int i = 0; i < n; i++) {
   if(max<dp[i]) max=dp[i];
 }
 free(dp);
return max;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"length of lis "<<lis(arr,n)<<endl;
  return 0;
}
