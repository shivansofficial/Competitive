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
void enqueue(char q[],char x,int &rear,int size)
{
  if(rear==size)
    cout<<"Overflow"<<endl;
  else
    {
      q[rear++]=x;
    }
}
void dequeue(char q[],int &front,int rear)
{
  if(front==rear)
    cout<<"Underflow"<<endl;
  else
  {
    q[front++]=0;
  }
}
char Front(char q[],int front)
{
  return q[front];
}
int size(int front,int rear)
{
  return (rear-front);
}
bool isempty(int front,int rear)
{
  return (front==rear);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  const int size=50;
  char q[size];
  int front=0,rear=0;
  for (int i = 0; i < s.size(); i++)
  {
    enqueue(q,s[i],rear,size);
  }
  char f=Front(q,front);
  cout<<"Front : "<<f<<endl;
  for (int i = front; i < rear; i++)
    cout<<q[i]<<endl;
  dequeue(q,front,rear);
  for (int i = front; i < rear; i++)
    cout<<q[i]<<endl;
  return 0;
}
