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
  char data;
  node * next;
}node;
void _append_list(node * head, char d)
{
  while(head->next!=NULL)
    head=head->next;
  node * temp=new node;
  head->next=temp;
  temp->data=d;
  temp->next=NULL;
  cout<<"Appended : "<<d<<endl;
}
node * init(node * head,char d)
{
  head=new node;
  head->data=d;
  head->next=NULL;
  cout<<head->data<<endl;
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
node * rev(node * head)
{
  node * prev,* curr,*next;
  prev=NULL;
  curr=head;
  while(curr!=NULL)
  {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  return prev;
}
bool compare(node * a,node *b)
{
  while(a && b)
  {
    if(a->data==b->data)
    {
      a=a->next;
      b=b->next;
    }
    else return 0;
  }
  if(a==NULL && b==NULL)
    return 1;
  return 0;
}
bool palin(node * head)
{
  node *slow=head,*fast=head;
  node * prev_slow=head,*second_half=NULL;
  node * middle=NULL;
  bool res= true;
  if(head!=NULL && head->next!=NULL)
  {
    while(fast!=NULL && fast->next!=NULL)
    {
      fast=fast->next->next;
      prev_slow=slow;
      slow=slow->next;
    }

    if(fast!=NULL)
    {
      middle=slow;
      slow=slow->next;
    }

    second_half=slow;
    prev_slow->next=NULL;
    second_half=rev(second_half);
    res=compare(head,second_half);
    second_half=rev(second_half);
    if(middle!=NULL)
    {
      prev_slow->next=middle;
      middle->next=second_half;
    }
    else prev_slow->next=second_half;
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  char str[]="abacaba";
  node * head=init(head,str[0]);
  palin(head)?cout<<"Palindrome"<<endl:cout<<"Not palindrome"<<endl;
  for (int i = 1;str[i]!='\0'; i++)
  {
    _append_list(head,str[i]);
    traverse(head);
    palin(head)?cout<<"Palindrome"<<endl:cout<<"Not palindrome"<<endl;
  }
  return 0;
}
