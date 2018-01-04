#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define endl '\n'
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
      cin>>a[i];
    int m;
    cin>>m;
    sort(a.begin(),a.end());
    int ans=INT_MAX;
    for(int i=0;i<=n-m;i++)
    {
      ans=min(ans,a[i+m-1]-a[i]);
    }
    cout<<ans<<endl;
  }
    return 0;
}
