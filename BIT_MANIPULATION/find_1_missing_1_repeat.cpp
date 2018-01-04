#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];

  int xor1=0,x=0,y=0;
  for(int i=0;i<n;i++)
    xor1=xor1^a[i];
  for(int i=1;i<=n;i++)
    xor1=xor1^i;

  int set_bit=xor1 & ~(xor1-1);
  for(int i=0;i<n;i++)
  {
    if(a[i] & set_bit)
      x=x^a[i];
    else
      y=y^a[i];
  }
  for(int i=1;i<=n;i++)
  {
    if(i & set_bit)
      x=x^i;
    else
      y=y^i;
  }
  cout<<x<<" "<<y;
  return 0;
}
