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
struct job
{
  int s,e,p;
};
bool end_time_sort(job s1,job s2)
{
  return (s1.e<s2.e);
}
int latest_non_conflict(job arr[],int i)
{
  int lo=0,hi=i-1;
  while(lo<=hi)
  {
    int mid=(lo+hi)/2;
    if(arr[mid].e<=arr[i].s)
    {
      if(arr[mid+1].e<=arr[i].s)
        lo=mid+1;
      else
        return mid;
    }
    else
      hi=mid-1;
  }
  return -1;
}
int findMaxProfit(job arr[],int n)
{
  sort(arr,arr+n,end_time_sort);
  int *table=new int[n];
  table[0]=arr[0].p;
  for (int i = 1; i < n; i++)
  {
    int incl_profit=arr[i].p;
    int l=latest_non_conflict(arr,i);
    if(l!=-1)
      incl_profit+=table[l];

    table[i]=max(incl_profit,table[i-1]);
  }
  int result=table[n-1];
  delete[] table;
  return result;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "The optimal profit is " << findMaxProfit(arr, n)<<endl;
  return 0;
}
