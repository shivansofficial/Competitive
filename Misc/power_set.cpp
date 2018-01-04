#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define enl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
    vector<vector<int> >ans;
    vector<int> sub;

  sort(a.begin(),a.end());
  for(int i=0;i<pow(2,n);i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i&(1<<j))
        sub.push_back(a[j]);
    }
    ans.push_back(sub);
    sub.clear();
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++)
    {for(int j=0;j<ans[i].size();j++)
      {
        cout<<ans[i][j]<<" ";
      }
      cout<<endl;
    }
  return 0;
}
