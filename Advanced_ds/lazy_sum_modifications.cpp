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
int tree[max]={0};
int lazy[max]={0};
void update_range_util(int si,int ss,int se,int us,int ue,int diff)
{
  if(lazy[si]!=0)
  {
    tree[si]+=(se-ss+1)*lazy[si];
    if(ss!=se)
    {
      lazy[2*si+1]+=lazy[si];
      lazy[2*si+2]+=lazy[si];
    }
    lazy[si]=0;
  }
  if(ss>se||ss>ue||se<us)
    return;
  if(ss>=us && se<=ue)
    {
      tree[si]+=(ss-se+1)*diff;
      if(ss!=se)
      {
        lazy[2*si+1]+=diff;
        lazy[2*si+2]+=diff;
      }
      return;
  }
  int mid=ss+(se-ss)/2;
  update_range_util(si*2+1,ss,mid,us,ue,diff);
  update_range_util(si*2+2,mid+1,se,us,ue,diff);
  tree[si]=tree[si*2+1]+tree[si*2+2];
}
void update_range(int n,int us,int ue,int diff)
{
  update_range_util(0,0,n-1,us,ue,diff);
}
int get_sum_util(int ss,int se,int qs,int qe,int si )
{
  if(lazy[si]!=0)
  {
    tree[si]+=(se-ss+1)*lazy[si];
    if(ss!=se)
    {
      lazy[2*si+1]+=lazy[si];
      lazy[2*se+2]+=lazy[si];
    }
    lazy[si]=0;
  }
  if(ss>se||ss>qe||se<qs)
    return 0;
  if(ss>=qs && se<=qe)
      return tree[si];
  int mid=ss+(se-ss)/2;
  return get_sum_util(ss,mid,qs,qe,2*si+1)+get_sum_util(mid+1,se,qs,qe,2*si+2);

}
int get_sum(int n,int qs,int qe)
{
  if(qs<0||qe>n-1||qs>qe)
  {
    cout<<"Invalid Input"<<endl;
    return -1;
  }
  return get_sum_util(0,n-1,qs,qe,0);
}
void construct_st_util(int arr[],int ss,int se,int si)
{
  if(ss>se)
  return;
  if(ss==se)
  {
    tree[si]=arr[ss];
    return;
  }
  int mid=ss+(se-ss)/2;
  construct_st_util(arr,ss,mid,2*si+1);
  construct_st_util(arr,mid+1,se,2*si+2);
  tree[si]=tree[si*2+1]+tree[si*2+2];
}
void construct_st(int arr[],int n)
{
  construct_st_util(arr,0,n-1,0);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin>>arr[i];
  construct_st(arr,n);
  cout<<get_sum(n,1,3)<<endl;
  update_range(n,1,5,10);
  cout<<get_sum(n,1,3)<<endl;
  return 0;
}
