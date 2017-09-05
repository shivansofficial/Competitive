#include<bits/stdc++.h>
using namespace std;
int main ()
{ int n, k;
  cin>>n>>k;
  int open=0;
  while(k--)
    { string s1;
      int s2,a=-1;
      map<int,int> t;
      cin>>s1;
      if(s1=="CLOSEALL") a=0;
      else { cin>>s2;a=s2;}
      if (a==0)
      { t.clear();
        cout<<"0"<<endl;
        continue;
      }
    if (t[a]==0)
    { t[a]++;
      open+=1;
     }
    else
    { t[a]--;
      open-=1;
    }
    cout<<open<<endl;
      }
  return 0;
}
