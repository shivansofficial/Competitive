#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

void bitonic(vector<int>arr,int n)
{
  if(n==0)
    return 0;
  int max_l = 1;
  int st=0,nst=0;
  int j=0;
  while(j<n-1)
  {
    while(j<n-1 && arr[j]<=arr[j+1])
      j++;
    while(j<n-1 && arr[j]>=arr[j+1])
    {
      if(j<n-1 && arr[j]>arr[j+1])
        nst = j+1;
      j++;
    }
    max_l = max(max_l,j-st+1);
    st = nst;
  }
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  bitonic(arr,n);
  return 0;
}
