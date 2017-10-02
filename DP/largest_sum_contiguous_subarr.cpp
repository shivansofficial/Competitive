#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
void maxSubArraySum(int a[],int n)
{ int start=0,end=0,s=0;
  int max_so_far=INT_MIN,max_ending_here=0;
  for (int i = 0; i <n; i++) {
    max_ending_here+=a[i];
    if(max_so_far<max_ending_here)
    {max_so_far=max_ending_here;
      start=s;end=i;}
    if(max_ending_here<0)
    {
      max_ending_here=0;
      s=i+1;
    }
  }
  cout<<"Max Sum"<<max_so_far<<endl;
  cout<<"start index "<<start<<"end index "<<end<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
  int n = sizeof(a)/sizeof(a[0]);
  maxSubArraySum(a, n);
  return 0;
}
