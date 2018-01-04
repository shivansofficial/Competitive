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
node * merge(node * a,node *b)
{
  node * result=NULL;
  if(a==NULL)
    return b;
  else if(b==NULL)
    return a;
  if(a->data<=b->data)
  {
    result=a;
    result->next=merge(a->next,b);
  }
  else
  {
    result=b;
    result->next=merge(a,b->next);
  }
  return result;
}
pair<node*,node*>split(node * head,node * a,node * b)
{
  node*fast=head->next,*slow=head;
  if(head==NULL||head->next==NULL)
  {
    a=head;
    b=NULL;
  }
  else
  {
    while(fast!=NULL && fast->next!=NULL)
    {

      slow=slow->next;
      fast=fast->next->next;
    }

    a=head;
    b=slow->next;
    slow->next=NULL;
  }
  return make_pair(a,b);
}
node * mergesort(node * head)
{
  if(head==NULL|| head->next==NULL)
    return head;
  node *a,*b;
  pair<node*,node*>s=split(head,a,b);
  a=s.first;
  b=s.second;
  a=mergesort(a);
  b=mergesort(b);
  head=merge(a,b);
  return head;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node * head=init(head,0);
  _append_list(head,15);
  _append_list(head,2);
  _append_list(head,17);
  _append_list(head,35);
  _append_list(head,26);
  _append_list(head,9);
  _append_list(head,31);
  _append_list(head,18);
  traverse(head);
  head=mergesort(head);
  traverse(head);
  return 0;
}
