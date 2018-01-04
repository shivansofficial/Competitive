#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int x=0,y=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='N')
        y++;
      else if(s[i]=='S')
        y--;
      else if(s[i]=='E')
        x++;
      else if(s[i]=='W')
        x--;
    }

  int x_f=true,y_f=true;
  if(x>0&& x_f)
    while(x-- )
    {
      cout<<"E";
      x_f=false;
    }

  if(y>0 && y_f)
    while(y--)
    {
      cout<<"N";
      y_f=false;
    }
  if(y<0 && y_f)
    while(y++)
      {
        cout<<"S";
      }
  if(x<0 && x_f)
    while(x++)
      cout<<"W";

  cout<<endl;
  }
  return 0;
}
