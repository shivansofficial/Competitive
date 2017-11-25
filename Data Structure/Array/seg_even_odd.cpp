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
#define X first
#define Y second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mod 1000000007
#define max 100007
#define itr ::iterator it
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define repp(X,a,Y) for (int (X) = a;(X) < (Y);++(X))
#define set(a, b) memset(a, b, sizeof(a));
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;pp
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vd> vvd;
typedef vector<pii> vii;
typedef vector<string> vs;
#define endl '\n'
void seg(int arr[],int n)
{
  int s=0,e=n-1;
  while(s<e)
  {
    while(arr[s]%2==0 && s<e)
      s++;
    while(arr[e]%2==1 && s<e)
      e--;
    swap(arr[s++],arr[e--]);
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {12, 34, 45, 9, 8, 90, 3};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  seg(arr,arr_size);
  for (int i = 0; i < arr_size; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}
