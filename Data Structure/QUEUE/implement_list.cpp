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

node * new_node(int d)
{
  node * temp=new node;
  temp->data=d;
  temp->next=NULL;
  return temp;
}
 void enqueue(int d,node **front,node **rear)
{
  node * temp=new_node(d);
  if(*rear==NULL)
  {
    *front=*rear=temp;
    return;
  }
  (*rear)->next=temp;
  *rear=temp;
}
node * dequeue(node ** front , node **rear)
{
  if(*front==NULL)
    return NULL;
  node * temp=*front;
  *front=(*front)->next;

  if(*front==NULL)
      *rear=NULL;
  return temp;
}
void traverse(node * front)
{
  node * temp=front;
  while(temp!=NULL)
  {
    cout<<temp->data<<endl;
    temp=temp->next;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node * front=NULL, * rear=NULL;
  enqueue(10,&front,&rear);
  enqueue(20,&front,&rear);
  enqueue(30,&front,&rear);
  enqueue(40,&front,&rear);
  enqueue(50,&front,&rear);
  traverse(front);
  node * n=dequeue(&front,&rear);
  if(n!=NULL)
    cout<<"Dequeue : "<<n->data<<endl;
  traverse(front);
  return 0;
}
