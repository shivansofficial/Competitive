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

void max_consec(vector<int>arr)
{
  int sum=0;
  sort(arr.begin(),arr.end());
  for(int i=0;i<n/2;i++)
    {
      sum -= 2*arr[i];
      sum += 2*arr[n-1-i];
    }
  cout<<sum;
}

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  max_consec(arr,n);
  return 0;
}
