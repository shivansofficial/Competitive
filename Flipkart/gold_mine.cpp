#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
#define endl '\n';
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>a[i][j];

    for(int j=m-1;j>=0;j--)
    {
      for(int i=0;i<n;i++)
      {
        int r=(j==m-1)?0:a[i][j+1];
        int du=((i==0)||(j==m-1))?0:a[i-1][j+1];
        int dd=((i==n-1)||(j==m-1))?0:a[i+1][j+1];
        a[i][j]+=max(r,max(du,dd));
      }
    }
    int res=a[0][0];
    for(int i=1;i<n;i++)
      res=max(res,a[i][0]);
    cout<<res<<endl;
  }

  return 0;
}
