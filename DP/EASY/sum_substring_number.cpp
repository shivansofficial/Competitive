#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  int n=s.size();
  int sum_digit[n];
  sum_digit[0]=s[0]-'0';
  int res=sum_digit[0];
  for(int i=1;i<n;i++)
  {
    sum_digit[i]=(i+1)*(s[i]-'0') + 10*sum_digit[i-1];
    res+=sum_digit[i];
  }
  cout<<res<<endl;
  return 0;
}
