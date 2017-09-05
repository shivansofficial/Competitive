#include<bits/stdc++.h>
using namespace std;
map<unsigned long  int,unsigned long  int> dp;

unsigned long  int maxx(unsigned long  int a)
{ if(a==0) return 0;
  else if(dp[a]!=0) return dp[a];
  else dp[a]=max(a,maxx(a/2)+maxx(a/3)+maxx(a/4));
   return dp[a];

}
int main ()
{ unsigned long  int n ;
   while(cin>>n)
  {

    cout<<maxx(n)<<"\n";
  }
  return 0;
}
