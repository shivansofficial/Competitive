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
node * intersect(node * a, node * b)
{
  node * dummy=init(dummy,-1);
  while(a!=NULL && b!=NULL)
  {
    if(a->data==b->data)
    {
      _append_list(dummy,a->data);
      a=a->next;
      b=b->next;
    }
    else if (a->data>b->data)
      b=b->next;
    else
      a=a->next;
  }
  return dummy->next;
}
node * recur_inter(node*a , node*b)
{
  if(a==NULL||b==NULL)
  return NULL;
  if(a->data>b->data)
    return recur_inter(a,b->next);
  if(a->data<b->data)
    return recur_inter(a->next,b);
  node * temp=new node;
  temp->data=a->data;
  temp->next=recur_inter(a->next,b->next);
  return temp;  
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node * a=init(a,1);
  _append_list(a,2);
  _append_list(a,3);
  _append_list(a,4);
  _append_list(a,5);
  _append_list(a,6);
  traverse(a);
  node * b=init(b,0);
  _append_list(b,2);
  _append_list(b,4);
  _append_list(b,6);
  _append_list(b,8);
  _append_list(b,10);
  _append_list(b,12);
  _append_list(b,14);
  traverse(b);
  node * c = intersect(a,b);
  traverse(c);
  node * d=recur_inter(a,b);
  traverse(d);
  return 0;
}
