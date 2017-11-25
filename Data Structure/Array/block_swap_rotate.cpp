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
void swap(int arr[],int f,int s,int d)
{
  int i,temp;
  for (int i = 0; i < d; i++)
  {
    temp=arr[f+i];
    arr[f+i]=arr[s+i];
    arr[s+i]=temp;
  }
}
void left_rotate(int arr[],int d,int n)
{
  if(d==0||d==n)
    return;
  if(n-d==d)
  {
    swap(arr,0,n-d,d);
    return;
  }
  if(d<n-d)
  {
    swap(arr,0,n-d,d);
    left_rotate(arr,d,n-d);
  }
  else
  {
    swap(arr,0,d,n-d);
    left_rotate(arr+n-d,2*d-n,d);
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[]={1,2,3,4,5,6,7};
  left_rotate(arr,4,7);
  for (int i = 0; i < 7; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}
