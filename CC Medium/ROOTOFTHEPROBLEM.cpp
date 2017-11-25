#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{ ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
cin>>t;
while(t--)
{ int n,r=0 ;
  cin>>n;
  for(int i=;i<n;i++)
  { int i,s;
    cin>>i>>s;
    r+=i-s;
  }
 cout<<r<<endl;
}
return 0;
}
