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
//#define max 100007
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
struct Box
{
  int h,w,d;
};
int compare(Box &a,Box &b)
{
  return(a.w*a.d > b.w*b.d);
}
int max_stack_height(Box arr[],int n)
{
  Box rot[3*n];
  int j=0;
  for (int i = 0; i < n; i++)
  {
    rot[j]=arr[i];
    j++;

    rot[j].h=arr[i].w;
    rot[j].d=max(arr[i].h,arr[i].d);
    rot[j].w=min(arr[i].h,arr[i].d);
    j++;

    rot[j].h=arr[i].d;
    rot[j].d=max(arr[i].h,arr[i].w);
    rot[j].w=min(arr[i].h,arr[i].w);
    j++;
  }
  n=3*n;

  sort(rot,rot+n,compare);
  for (int i = 0; i < n; i++)
    cout<<rot[i].h<<" "<<rot[i].w<<" "<<rot[i].d<<endl;
  int msh[n];
  for (int i = 0; i < n; i++)
    msh[i]=rot[i].h;

  for (int i = 1; i < n; i++)
  {
    for (int  j = 0; j<i; j++)
    {
      if(rot[j].w>rot[i].w && rot[j].d>rot[i].d && msh[i]<msh[j]+rot[i].h)
        msh[i]=msh[j]+rot[i].h;
    }
  }
  int max=-1;
  for (int i = 0; i < n; i++)
  {
    if(msh[i]>max)
      max=msh[i];
  }
  return max;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"The maximum possible height of stack is : "<<endl<<max_stack_height(arr,n)<<endl;
  return 0;
}
