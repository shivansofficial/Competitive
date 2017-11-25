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
int search(int arr[],int l,int h,int key)
{
  if(l>h)
    return -1;
  int mid=(l+h)/2;
  if(arr[mid]==key)
      return mid;
  if(arr[l]<=arr[mid])
  {
    if(key>=arr[l] && key<=arr[mid])
      return search(arr,l,mid-1,key);
    return search(arr,mid+1,h,key);
  }
  if(key>=arr[mid] && key<=arr[h])
    return search(arr,mid+1,h,key);
  return search(arr,l,mid-1,key);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int key = 6;
  int i = search(arr, 0, n-1, key);
  if (i != -1) cout << "Index: " << i << endl;
  else cout << "Key not foundn";
  return 0;
}
