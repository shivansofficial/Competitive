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
#include<list>
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
class LRUcache
{
  list<int> dq;
  map<int,list<int>::iterator> hash;
  int csize;

  public:
    LRUcache(int);
    void refer(int);
    void display();
};
LRUcache::LRUcache(int x)
{
  csize=x;
}
void LRUcache::refer(int x)
{
  if(hash.find(x)==hash.end())
  {
    if(dq.size()==csize)
    {
      int last=dq.back();
      dq.pop_back();
      hash.erase(last);
    }
  }
  else
    dq.erase(hash[x]);

  dq.push_front(x);
  hash[x]=dq.begin();
}
void LRUcache::display()
{
  for (list<int>::iterator it=dq.begin(); it!=dq.end(); it++)
  {
    cout<<*it<<" ";
  }
  cout<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  LRUcache ca(4);

  ca.refer(1);
  ca.refer(2);
  ca.refer(3);
  ca.refer(1);
  ca.refer(4);
  ca.refer(5);
  ca.display();
  return 0;
}
