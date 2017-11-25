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
typedef struct Node
{
  int data;
  Node * next;
}Node;

void _append_list(Node * head,int d)
{
  while(head->next!=NULL)
    head=head->next;

  Node * temp= new Node;
  head->next=temp;
  temp->data=d;
  temp->next=NULL;
  cout<<"Appended: "<<d<<endl;
}
Node * init(Node * head,int d)
{
  head = new Node;
  head->data=d;
  head->next=NULL;
  for(int i=1;i<15;i++)
    _append_list(head,d+i);
  return head;
}
Node * _prepend(Node * head,int d)
{
  Node * temp=new Node;
  temp->data=d;
  temp->next=head;
  return temp;
}
int length(Node * head,int n)
{
  if(head->next==NULL)
      return n+1;
  else
    return length(head->next,n+1);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  Node * head=init(head,0);
  head=_prepend(head,-1);
  cout<<"Length of the list: "<<length(head,0)<<endl;
  return 0;
}
