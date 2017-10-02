#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    string n;
    int a[10]={0};
    cin>>n;
    for(int i=0;i<n.length();i++)
    {
        if(a[int(n[i])-48]==1)
          continue;
        a[int(n[i])-48] = 1;
    }
    for(int i=0;i<10;i++)
    {
      cout<<i<<" "<<a[i]<<endl;
    }
    /*for (int i = 0; i <10; i++) {
      if(a[])
    }
*/


  }
  return 0;
}
