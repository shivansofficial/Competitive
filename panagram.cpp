#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{ ios::sync_with_stdio(false);
  cin.tie(NULL);

int t ;
while(t--)
{ string p,s;
  getline(cin,p);
  getline(cin,s);
  int i;
  for( i=0;i<s.length();i++)
  { if(p[s[i]]==0) continue;
    p[s[i]]=0;
  }
for(i=0;i<p.length();i++)
  cout<<p[i];

}
return 0;
}
