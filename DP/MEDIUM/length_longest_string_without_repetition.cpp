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
int longest_sub_array(string s)
{
  int n=s.length();
  int cur_len=1;
  int max_len=1;
  int prev_index;
  int *visited=new int[256];

  for (int i = 0; i < 256; i++)
    visited[i]=-1;

  visited[s[0]]=0;

  for (int i = 1; i <s.length(); i++)
  {
    prev_index=visited[s[i]];

    if(prev_index==-1||i-cur_len>prev_index)
      cur_len++;
    else
    {
      if(cur_len>max_len)
        max_len=cur_len;

      cur_len=i-prev_index;
    }
    visited[s[i]]=i;
  }
  if(cur_len>max_len)
    max_len=cur_len;
  delete[] visited;
  return max_len;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  cout<<s<<endl;
  cout<<"Length of longest non-repeating substring :"<<longest_sub_array(s)<<endl;
  return 0;
}
