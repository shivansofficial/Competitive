#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<list>
#include<string>
#include<algorithm>
#include<math.h>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
typedef long long ll;
#define endl '\n'

using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int i;
    for(i=n/2+1;i<=n+n/2;i++)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}
