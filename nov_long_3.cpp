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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {

    string s;
    string a="ab";
    int n,p;
    int flag=-1;
    cin>>n>>p;
    while(p>4 && p%2==0)
    {
      p/=2;
    }
    if(n<=2||p<=2)
      cout<<"impossible"<<endl;
    else if(n%p!=0)
      cout<<"impossible"<<endl;
    else if(p%2==0)
    {
      for (int  i = 0; i < p/2; i++)
      {
        s+=a;
        reverse(a.begin(),a.end());
      }
      flag=0;
    }
    else if(p%2==1)
    {
      for (int i = 0; i < p/2; i++)
      {
        s+=a;
      }
      s+="a";
      flag=0;
    }

    if(flag==0)
    {
        for(int i=0;i<n/p;i++)
      {
        cout<<s;
      }
        cout<<endl;
    }
  }
  return 0;
}
