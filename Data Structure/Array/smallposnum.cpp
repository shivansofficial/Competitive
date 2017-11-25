#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void swap (int*a , int*b)
{int temp=*a;
  *a=*b;
  *b=temp;
}
int segregate(int a[],int s)
{ int j=0;
  for(int i=0;i<s;i++)
  { if(a[i]=<0)
    { swap(&a[i],&a[j]);
    j++; }

  }
return j;
}
int findmissingelement(int a[],int s)
{ for(int i=0;i<s;i++)
  { if((abs(a[i])-1)<s && a[abs(a[i])-1]>0)
    a[abs(a[i])-1]=-a[abs(a[i])-1];

  }
  for(int i=0;i<s;i++)
  {
    if(a[i]>0) return i+1;
  }
}
int findmissing(int a[],int s)
{ int shift =segregate(a,s);
  return findmissingelement(a+shift,s-shift);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a[]={ 2, 3, -7, 6, 8, 1, -10, 15 };
  int size=sizeof(a)/sizeof(a[0]);
  int missing=findmissing(a,size);
  cout<<missing<<endl;
  return 0;
}
