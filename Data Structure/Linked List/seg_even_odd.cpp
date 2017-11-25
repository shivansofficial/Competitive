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
  for (int i = 1; i <8; i++)
    _append_list(head,d+i);
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
node * seg_even_odd(node * head)
{
  node * end=head,*prev=NULL,*curr=head;
  while(end->next!=NULL)
    end=end->next;
  node * new_end=end;
  while(curr->data%2!=0 && curr!=end)
  {
    new_end->next=curr;
    curr=curr->next;
    new_end->next->next=NULL;
    new_end=new_end->next;
  }
  if(curr->data%2==0)
  {
    head=curr;
    while(curr!=end)
    {
      if(curr->data%2==0)
      {
        prev=curr;
        curr=curr->next;
      }
      else
      {
        prev->next=curr->next;
        curr->next=NULL;
        new_end->next=curr;
        new_end=curr;
        curr=prev->next;
      }
    }
  }
  else
    prev=curr;
  if(new_end!=end && end->data%2!=0)
  {
    prev->next=end->next;
    end->next=NULL;
    new_end->next=end;
  }
  return head;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node * head=init(head,0);
  traverse(head);
  head=seg_even_odd(head);
  traverse(head);
  return 0;
}
