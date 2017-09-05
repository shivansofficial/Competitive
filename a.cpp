#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int fact(int n)
{
  return n<=1?1:n*fact(n-1);
}
int countsmall(char*s,int low, int high )
{ int count=0;
  for (int i = low+1; i <=high; i++) {
    if(s[low]>s[i]) count++;
  }
  return count;
}
int findrank(char *s)
{ int length=strlen(s);
  int mul=fact(length);
  int rank=1;
  for(int i;i<length;i++)
  { mul/=length -i;
    rank+=countsmall(s,i,length-1)*mul;

  }
  return rank;
}
int main()
{ ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s="string";
  cout<<findrank(s)<<endl;
  return 0;
}
