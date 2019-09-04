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

int number_of_digit(int n)
{
	int digit=0;

	while(n>0)
	{
		digit++;
		n=n/10;
	}

	return digit;
}

void answer(int n, int sum, vector<pair<int,int> > &final)
{
  map<int,int> hash;
	vector<int> each_digit;
  int save_n = n;
	int digits_first=0;
  int digits_second=0;

	while(n>0)
	{
		each_digit.push_back(n%10);
		n=n/10;
		digits_first++;
	}

	reverse(each_digit.begin(),each_digit.end());

	for(int i=0; i<each_digit.size(); i++)
	{
		int second_pair = 0;
		digits_second = digits_first - 2;

		for(int j=0; j<each_digit.size(); j++)
		{
			if(i != j)
			{
				second_pair += each_digit[j] * pow(10,digits_second);
				digits_second--;
			}
		}

		if((second_pair+save_n==sum) && (hash[save_n]==0))
		{
			final.push_back(make_pair(save_n, second_pair));
      hash[save_n]++;
		}
	}
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;

  while(t--)
  {
    int n;
    vector <pair<int,int> > final;

    cin>>n;

    for(int i=0; i<=n; i++)
      answer(i,n,final);

    cout<<final.size()<<" pairs found"<<endl;

    for(int i=0; i<final.size(); i++)
    {
      int digits_first = number_of_digit(final[i].first);
      int digits_second = number_of_digit(final[i].second);

      if(digits_first - digits_second == 1)
      {
        cout<<final[i].first<<" + "<<final[i].second<<" = "<<n<<endl;
      }
      else
      {
        int prepend_zeros = digits_first - digits_second - 1;

        cout<<final[i].first<<" + ";

        for(int j=0; j<prepend_zeros; j++)
          cout<<0;

        cout<<final[i].second<<" = "<<n<<endl;
      }
    }
  }
  return 0;
}
