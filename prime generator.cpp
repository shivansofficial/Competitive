#include<bits/stdc++.h>
using  namespace std;
int main ()
{ int t ;
  cin>>t;
  while(t--)
  { int n,m;
    cin>>n>>m;
    vector<bool>arr(1000000000,1);
    arr[0]=arr[1]=0;
    for(int i=2;i*i<=m;i++)
    { if(arr[i])
      { int multiple=max(n/i,2);
        for(int j=i*multiple;j<=m;j+=i)
        {
          arr[j]=0;
        }
      }

    }
    for(int i=n;i<=m;i++)
    { if (arr[i])
      {cout<<i<<"\n";}

    }
    cout<<"\n";
  }
  return 0;
}
