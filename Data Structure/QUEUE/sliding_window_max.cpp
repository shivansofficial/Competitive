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
void printKMax(int arr[],int n,int k)
{
  deque<int> q(k);
  int i;
  for (int i = 0; i < k; i++)
  {
    while((!q.empty()) && arr[i]>=arr[q.back()])
      q.pop_back();

    q.push_back(i);
  }
  for (i=k; i < n; i++)
  {
    cout<<arr[q.front()]<<" ";

    while((!q.empty()) && q.front()<=i-k)
      q.pop_front();

    while((!q.empty()) && arr[i]>=arr[q.back()])
      q.pop_back();

    q.push_back(i);
  }
  cout<<arr[q.front()]<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {12, 1, 78, 90, 57, 89, 56};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = 3;
  printKMax(arr, n, k);
  return 0;
}
