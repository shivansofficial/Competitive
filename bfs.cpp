#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
#define endl '\n'
void print_pair(int a[],int n,int sum)
{ bool pair[MAX]={0};
  for(int i=0;i<n;i++)
  { int temp=sum-a[i];
    if(temp>=0 && pair[temp]==1)
    cout<<"Pair"<<a[i]<<temp<<endl;
    pair[a[i]]=1;
  }

}

int main{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int A[]={1, 4, 45, 6, 10, 8};
  int sum=10;
  int size=sizeof(A)/sizeof(A[0]);
  print_pair(A,size,sum);

  return 0;
}
