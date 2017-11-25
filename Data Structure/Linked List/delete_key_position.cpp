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
void add_after(Node * head,int key,int d)
{
  while(head->next->data!=key)
    head=head->next;
  Node * temp=new Node;
  temp->data=d;
  temp->next=head->next;
  head->next=temp;
}
void _append_list(Node * head ,int d)
{
  while(head->next!=NULL)
    head=head->next;
  Node * temp=new Node;
  head->next=temp;
  temp->data=d;
  temp->next=NULL;
  cout<<"Appended : "<<d<<endl;
}
Node * _prepend(Node * head,int d)
{
  Node * temp=new Node;
  temp->data=d;
  temp->next=head;
  return temp;
}
Node * init(Node * head,int d)
{
  head=new Node;
  head->next=NULL;
  head->data=d;
  for (int i = 1; i < 15; i++)
    _append_list(head,d+i);
  return head;
}
void traverse(Node * head)
{
  if (head==NULL)
    cout<<"Empty";
  else
    {
      while(head!=NULL)
    {
      cout<<head->data<<" ";
      head=head->next;
    }
    cout<<endl;
    }
}
Node * remove_pos(Node * head,int p)
{
  if(head==NULL)
    return head;

  Node*temp=head;
  if(p==0)
  {
    temp=head->next;
    delete head;
    return temp;
  }

  for (int i = 0; temp!=NULL && i <p-1; i++)
    temp=temp->next;

  if(temp==NULL||temp->next==NULL)
      return head;

  Node*next=temp->next->next;
  delete temp->next;
  temp->next=next;
  return head;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  Node * head=init(head,0);
  head=_prepend(head,-1);
  add_after(head,4,35);
  traverse(head);
  head = remove_pos(head,0);
  traverse(head);
  return 0;
}
