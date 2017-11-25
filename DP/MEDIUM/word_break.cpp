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
int dictionaryContains(string word)
{
  string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
  int size = sizeof(dictionary)/sizeof(dictionary[0]);
  for (int i = 0; i < size; i++)
  {
    if(dictionary[i].compare(word)==0)
      return true;
  }
  return false;
}
int wordBreak(string str)
{
    int n=str.size();
    if(n==0)
      return 1;
    bool wb[n+1];
    memset(wb,false,sizeof(wb));
    for (int i = 1; i <=n; i++)
    {
      if(wb[i]==false && dictionaryContains(str.substr(0,i)))
        wb[i]=true;

      if(wb[i]==true)
      {
        if(i==n)
          return true;
        for (int j = i+1; j <=n; j++)
        {
          if(wb[j]==false && dictionaryContains(str.substr(i,j-i)))
            wb[j]=true;

          if(j==n && wb[j]==true)
            return true;
        }
      }
    }
    return false;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  wordBreak("ilikesamsung")? cout <<"Yes"<<endl: cout << "No"<<endl;
  wordBreak("iiiiiiii")? cout <<"Yes"<<endl: cout << "No"<<endl;
  wordBreak("")? cout <<"Yes"<<endl: cout << "No"<<endl;
  wordBreak("ilikelikeimangoiii")? cout <<"Yes"<<endl: cout << "No"<<endl;
  wordBreak("samsungandmango")? cout <<"Yes"<<endl: cout << "No"<<endl;
  wordBreak("samsungandmangok")? cout <<"Yes"<<endl: cout << "No"<<endl;
  return 0;
}
