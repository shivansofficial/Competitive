#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
#define mod 1000000007
/*long long count(int n,bool flag)
{
  if(n==1)
    return 1;
  if(n<0)
    return 0;
  if(flag==0)
    return (count(n-1,0)+ count(n-1,1));
  else if(flag==1)
    return count(n-1,0);
}*/
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    //long long ans=2*count(n-1,0)%mod+count(n-1,1)%mod;
    vector<int>b(n+1,0);
    vector<int>s(n+1,0);
    b[0]=0,s[0]=0,b[1]=1,s[1]=1;
    for(int i=2;i<=n;i++)
    {
      b[i]=s[i-1]%mod;
      s[i]=(b[i-1]+s[i-1])%mod;
      
    }
    long long ans=(b[n]+s[n])%mod;
    cout<<(ans*ans)%mod<<endl;
  }
  return 0;
}
