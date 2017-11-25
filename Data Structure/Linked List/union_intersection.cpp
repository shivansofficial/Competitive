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
typedef struct node
{
  int data;
  node * next;
}node;
void _append_list(node * head, int d)
{
  while(head->next!=NULL)
    head=head->next;
  node * temp=new node;
  head->next=temp;
  temp->data=d;
  temp->next=NULL;
  cout<<"Appended : "<<d<<endl;
}
node * init(node * head,int d)
{
  head=new node;
  head->data=d;
  head->next=NULL;
  return head;
}
void traverse(node * head)
{
  if(head!=NULL)
  while(head!=NULL)
  {
    cout<<head->data<<" ";
    head=head->next;
  }
  else
    cout<<"Empty";
    cout<<endl;
}
node * intersect(node * a,node *b)
{
  node *res=init(res,-1);
  node * h1=a,*h2=b;
  map<int,int> hash;
  while(h1!=NULL)
  {
      hash[h1->data]=1;
      h1=h1->next;
  }
  while(h2!=NULL)
  {
    if(hash[h2->data]==1)
      _append_list(res,h2->data);
    h2=h2->next;
  }
  return res->next;
}
node * _union(node * a,node *b)
{
  node * res=init(res,-1);
  node * h1=a,*h2=b;
  map<int,int> hash;
  while(h1!=NULL)
  {
    _append_list(res,h1->data);
      hash[h1->data]=1;
      h1=h1->next;
  }
  while(h2!=NULL)
  {
    if(!hash[h2->data])
      _append_list(res,h2->data);
    h2=h2->next;
  }
  return res->next;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node * a=init(a,0);
  _append_list(a,2);
  _append_list(a,3);
  _append_list(a,5);
  _append_list(a,6);
  _append_list(a,8);
  _append_list(a,9);
  traverse(a);
  node * b=init(b,0);
  _append_list(b,1);
  _append_list(b,4);
  _append_list(b,5);
  _append_list(b,9);
  _append_list(b,11);
  traverse(b);
  node * u=_union(a,b);
  traverse(u);
  node * i=intersect(a,b);
  traverse(i);
  return 0;
}
