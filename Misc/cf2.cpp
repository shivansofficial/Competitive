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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<pii> vii;
typedef vector<string> vs;
#define endl '\n'
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;

  while(t--)
  { vi a[26];
    string s;
    cin>>s;
    int l=s.length();
    int i,j;
    rep(i,l)
    { a[int(s[i])-97]++;
      a[int(s[i])-97].pb(i);
    }
    rep(i,26)
    { rep(j,a[i].length())
      cout<<i<<" "<<a[i]<<" "<<a[i][j]<<endl;

    }

  }


  return 0;
}
