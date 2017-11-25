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
class Stack
{
  static const int max=100;
  int arr[max];
  int top;
  public:
  Stack(){ top=-1;}
  bool is_empty();
  bool is_full();
  int pop();
  void push(int x);
};
bool Stack::is_empty()
{
  if(top==-1)
    return true;
  return false;
}
bool Stack::is_full()
{
  if (top==max-1)
    return true;
  return false;
}
int Stack::pop()
{
  int x=arr[top--];
  return x;
}
void Stack::push(int x)
{
  if(is_full())
  {
    cout<<"Overflow"<<endl;
    return;
  }
  arr[++top]=x;
}
class Special_class:public Stack
{
  Stack min;
  public:
  int pop();
  void push(int x);
  int get_min();
};
void Special_class::push(int x)
{
  if(is_empty())
  {
    Stack::push(x);
    min.push(x);
  }
  else
  {
    Stack::push(x);
    int y=min.pop();
    min.push(y);
    if(x<y)
      min.push(x);
    else
      min.push(y);
  }
}
int Special_class::pop()
{
  int x=Stack::pop();
  min.pop();
  return x;
}
int Special_class::get_min()
{
  int x=min.pop();
  min.push(x);
  return x;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  Special_class s;
  s.push(10);
  s.push(20);
  s.push(30);
  cout<<s.get_min()<<endl;
  s.push(5);
  cout<<s.get_min()<<endl;
  return 0;
  return 0;
}
