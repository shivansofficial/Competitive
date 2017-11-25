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
  for (int i = 1; i <5; i++)
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
void detect_remove_loop(node * head)
{
  if(head==NULL && head->next==NULL)
    return;
  node * slow=head,*fast=head;
  slow=slow->next;
  fast=fast->next->next;
  while(fast && fast->next)
  {
    if(slow==fast)
      break;
    slow=slow->next;
    fast=fast->next->next;
  }
  if(slow==fast)
  {
    slow=head;
    while(slow->next!=fast->next)
    {
      slow=slow->next;
      fast=fast->next;
    }
    fast->next=NULL;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node * head=init(head,0);
  traverse(head);
  head->next->next->next->next->next = head->next->next;
  detect_remove_loop(head);
  traverse(head);
  return 0;
}
