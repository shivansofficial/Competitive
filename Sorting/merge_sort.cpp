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
void merge(int arr[],int l,int m,int r)
{
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;
  int L[n1],R[n2];
  for (i = 0; i < n1; i++)
    L[i]=arr[l+i];
  for ( i = 0; i <n2; i++)
    R[i]=arr[m+1+i];
  i=0;
  j=0;
  k=l;
  while(i<n1 && j<n2)
  {
    if(L[i]<=R[j])
      arr[k++]=L[i++];
    else
      arr[k++]=R[j++];
  }
  while(i<n1)
  {
    arr[k++]=L[i++];
  }
  while(j<n2)
  {
    arr[k++]=R[j++];
  }
}
void mergeSort(int arr[],int l,int r)
{
  if(l<r)
  {
    int m=l+(r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  mergeSort(arr, 0, arr_size - 1);
  for (int i = 0; i < arr_size; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}
