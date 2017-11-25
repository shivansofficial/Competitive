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
void update_value_util(int * st,int ss,int se,int i,int diff,int si)
{
  if(i<ss||i>se)
    return;
  st[si]+=diff;
  if(se!=ss)
  {
    int mid=ss+(se-ss)/2;
    update_value_util(st,ss,mid,i,diff,2*si+1);
    update_value_util(st,mid+1,se,i,diff,2*si+2);
  }
}
void update_value(int arr[],int * st,int n,int i,int new_val)
{
  if(i<0||i>n-1)
  {
    cout<<"Invalid Input"<<endl;
    return;
  }
  int diff=new_val-arr[i];
  arr[i]=new_val;
  update_value_util(st,0,n-1,i,diff,0);
}
int get_sum_util(int * st,int ss,int se,int qs,int qe,int si)
{
  if(qs<=ss && qe>=se)
    return st[si];
  if (se < qs || ss > qe)
    return 0;
  int mid=ss+(se-ss)/2;
  return get_sum_util(st,ss,mid,qs,qe,2*si+1)+get_sum_util(st,mid+1,se,qs,qe,2*si+2);
}
int get_sum(int * st,int n,int qs,int qe)
{
  if(qs<0||qe>n-1||qs>qe)
  {
    cout<<"Invalid Input"<<endl;
    return -1;
  }
  return get_sum_util(st,0,n-1,qs,qe,0);
}
int construct_st_util(int arr[],int ss,int se,int * st,int si)
{
  if(ss==se)
  {
    st[si]=arr[ss];
    return arr[ss];
  }
  int mid=ss+(se-ss)/2;
  st[si]=construct_st_util(arr,ss,mid,st,si*2+1)+ construct_st_util(arr,mid+1,se,st,si*2+2);
  return st[si];
}
int * construct_st(int arr[],int n)
{
  int x=ceil(log2(n));
  int max_size=2*pow(2,x);
  int * st=new int[max_size];
  // vector<int>st(max_size,0);
  construct_st_util(arr,0,n-1,st,0);
  return st;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int * st=construct_st(arr,n);
  cout<<"Sum of value in given range: "<<get_sum(st,n,1,3)<<endl;
  update_value(arr,st,n,1,10);
  cout<<"Sum of value in given range: "<<get_sum(st,n,1,3)<<endl;
  return 0;
}
