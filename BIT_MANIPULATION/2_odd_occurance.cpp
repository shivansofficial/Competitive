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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vd> vvd;
typedef vector<pii> vii;
typedef vector<string> vs;
#define endl '\n'
void two_odd(int arr[],int n)
{
  int xor2=arr[0];
  int set_bit;
  int x=0,y=0;
  for (int i = 1; i <n; i++)
    xor2^=arr[i];
  set_bit=xor2 & ~(xor2-1);
  for (int i = 0; i <n; i++)
  {
    if(arr[i]&set_bit)
      x^=arr[i];
    else
      y^=arr[i];
  }
  cout<<x<<" "<<y<<" ";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[]={4, 2, 4, 5, 2, 3, 3, 1};
  int size=sizeof(arr)/sizeof(arr[0]);
  two_odd(arr,size);
  cout<<endl;
  return 0;
}
