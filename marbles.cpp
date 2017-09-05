#include<bits/stdc++.h>
using namespace std;

unsigned long long ncr( int n , int r)
{ if(n==r) return n;
  else if(r>n/2) r=n-r;
  unsigned long long ans=1;
  for(int i=1;i<=r;i++)
  { ans*=n-r+i;
    ans/=i;
  }
  return ans;
}
unsigned long long multnom(int n , int r)
{ unsigned long long ans=ncr(n+r-1,r-1);
  return ans;
}
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n,k;
    cin>>n>>k;
    if(n==k) cout<<"1"<<endl;

    else  cout<<multnom(n-k,k)<< endl;
  }
return 0;
}
