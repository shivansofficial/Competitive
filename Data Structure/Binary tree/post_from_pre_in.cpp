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
int search(int in[],int x,int n)
{
  for (int i = 0; i <n; i++)
    if(in[i]==x)
      return i;
    return -1;
}
void post(int in[],int pre[],int n)
{
  int root=search(in,pre[0],n);
  if(root!=0)
    post(in,pre+1,root);
  if(root!=n-1)
    post(in+root+1,pre+root+1,n-root-1);
  cout<<pre[0]<<" ";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int in[] = {4, 2, 5, 1, 3, 6};
  int pre[] =  {1, 2, 4, 5, 3, 6};
  int n=sizeof(in)/sizeof(in[0]);
  cout<<"Post :"<<endl;
  post(in,pre,n);
  cout<<endl;
  return 0;
}
