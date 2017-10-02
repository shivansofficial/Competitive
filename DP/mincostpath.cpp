#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
int mincost(int c[3][3],int m,int n)
{ int tc[m+1][n+1];
  tc[0][0]=c[0][0];
  for (int i = 1; i <=m; i++) {
   tc[i][0]=tc[i-1][0]+c[i][0];
  }
  for (int i = 1; i <=n; i++) {
     tc[0][i]=tc[0][i-1]+c[0][i];
  }
  for (int i = 1; i <=m; i++) {
     for (int j = 1; j <=n; j++) {
       tc[i][j]=c[i][j]+ min(tc[i-1][j],min(tc[i][j-1],tc[i-1][j-1]));
     }
  }
  return tc[m][n];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
  cout<<mincost(cost,2,2);
  return 0;
}
