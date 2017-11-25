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
  node* next;
}Node;
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
Node * _search_list(node * head,int key)
{
  if(head==NULL)
    return NULL;
  if(head->data==key)
    return head;
  return _search_list(head->next,key);
}
Node * swap(Node * head, int x,int y)
{
  if(x==y) return head;
  Node * prevx=NULL,*currx=head;
  while(currx && currx->data!=x)
  {
    prevx=currx;
    currx=currx->next;
  }
  Node * prevy=NULL,*curry=head;
  while(curry && curry->data!=y)
  {
    prevy=curry;
    curry=curry->next;
  }
  if(!currx||!curry)
    return head;
  if(prevx!=NULL)
    prevx->next=curry;
  else
    head=curry;

  if(prevy!=NULL)
    prevy->next=currx;
  else
    head=currx;

  Node * temp=curry->next;
  curry->next=currx->next;
  currx->next=temp;
  return head;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node * head=init(head,0);
  traverse(head);
  head=swap(head,0,3);
  traverse(head);
  return 0;
}
