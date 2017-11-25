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
{int data;
  node *left,*right;
}node;
node * newNode(int d)
{ node*temp = new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}

void printVerticalOrder(node*root)
{ if(!root) return;
  map<int,vector<int> >m;
  int hd=0;
  queue<pair<node*,int> > q;
  q.push(make_pair(root,hd));
  while(!q.empty())
  { pair<node*,int> temp=q.front();
    q.pop();
    node*node=temp.first;
    hd=temp.second;
    m[hd].push_back(node->data);
    if(node->left!=NULL) q.push(make_pair(node->left,hd-1));
    if(node->right!=NULL) q.push(make_pair(node->right,hd+1));

  }
 map<int,vector<int> >::iterator it;
 for(it=m.begin();it!=m.end();it++)
 {for(int i=0;i<it->second.size();i++)
   { cout<<it->second[i];

   }
  cout<<endl;
 }

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->left->right = newNode(8);
  root->right->right->right = newNode(9);
  root->right->right->left= newNode(10);
  root->right->right->left->right= newNode(11);
  root->right->right->left->right->right= newNode(12);
    printVerticalOrder(root);
    return 0;
}
