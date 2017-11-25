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


void printNGE(int arr[], int n)
{
  stack <int> s;
  int element,next,i;
  s.push(arr[0]);
  for (int i = 1; i <n; i++)
  {
    next=arr[i];
    if(!s.empty())
        {
          element=s.top();
          s.pop();
            while(element < next)
            {
            cout<<"Next greatest element for "<<element<<"---->"<<next<<endl;
            if(s.empty())
              break;
            element=s.top();
            s.pop();
            }
            if(element>next)
              s.push(element);
        }
   s.push(arr[i]);
  }
  while(!s.empty())
  {
    element=s.top();
    s.pop();
    cout<<"Next greatest element for "<<element<<"---->"<<-1<<endl;
  }
}


int main() {
	int arr[]= {11, 13, 21, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}
