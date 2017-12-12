#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int> ans(1,0);
  for(int i=0;i<n;i++)
  {
    int cur=ans.size();
    for(int j=cur-1;j>=0;j--)
      ans.push_back(ans[j]+(1<<i));
  }

  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}
