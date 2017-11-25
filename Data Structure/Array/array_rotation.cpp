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
//#define gcd(a,b) __gcd((a),(b))
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
int hcf(int a,int b)
{
  if(b==0)
    return a;
  else
    return hcf(b,a%b);
}
void left_rotate(int arr[],int d,int n)
{
  int i,j,k,temp;
  for (int i = 0; i < hcf(d,n); i++)
  {
    temp=arr[i];
    j=i;
    while(1)
    {
      k=j+d;
      if(k>=n)
        k=k-n;
      if(k==i)
        break;
      arr[j]=arr[k];
      j=k;
    }
    arr[j]=temp;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[]={1,2,3,4,5,6,7};
  left_rotate(arr,2,7);
  for (int i = 0; i < 7; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}
