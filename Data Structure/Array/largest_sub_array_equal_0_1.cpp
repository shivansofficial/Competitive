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
void findSubArray(int arr[],int n)
{
  int max_size=-1,start_index;
  int sum_left[n];
  int min,max;
  sum_left[0]=(arr[0]==0?-1:1);
  min=max=sum_left[0];
  for (int i = 1; i < n; i++)
  {
    sum_left[i]=sum_left[i-1]+(arr[i]==0?-1:1);
    if(sum_left[i]<min)
      min=sum_left[i];
    if(sum_left[i]>max)
      max=sum_left[i];
  }
  vector<int> hash(max-min+1,-1);
  for (int i = 0; i < n; i++)
  {
    if(sum_left[i]==0)
      {
        max_size=i+1;
        start_index=0;
      }
    if(hash[sum_left[i]-min]==-1)
      hash[sum_left[i]-min]=i;
    else
    {
      if(i-hash[sum_left[i]-min]>max_size)
        {
          max_size=i-hash[sum_left[i]-min];
          start_index=hash[sum_left[i]-min]+1;
        }
    }
  }
  if(max_size==-1)
    cout<<"No such subarray"<<endl;
  else
    cout<<"Length : "<<max_size<<" Index : "<< start_index <<" to "<<start_index+max_size-1<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] =  {1, 0, 0, 1, 0, 1, 1};
  int size = sizeof(arr)/sizeof(arr[0]);
  findSubArray(arr, size);
  return 0;
}
