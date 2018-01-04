#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  int n=s.size();
  string ans;
  ans.resize(n);
  int o=(n-1)/2,e=(n-1)/2;
  for(int i=0;i<n;i++)
  {
    if((n-i)%2==1)
    {
    ans[o]=s[i];
    e--;
    }
    else if((n-i)%2==0)
    {
      ans[e]=s[i];
      o++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
