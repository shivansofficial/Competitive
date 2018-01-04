#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
  int n,r,g,b;
  cin>>n>>r>>g>>b;
  int left=n-(r+g+b);
  long long int fact[n];
  fact[0]=1;
  for(int i=1;i<=n;i++)
    fact[i]=i*fact[i-1];
  int sum=0;
  for(int i=0;i<=left;i++)
  {
    for(int j=0;j<=(left-i);j++)
    {
      int k=left-(i+j);
      sum+=fact[n]/(fact[i+r]*fact[j+g]*fact[k+b]);
    }
  }
  cout<<sum<<endl;
}
