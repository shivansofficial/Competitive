#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
bool is_safe(vector<vector<int> > s,int row,int col,int num)
{
  for(int i=0;i<s.size();i++)
    if(s[row][i]==num)
      return false;

  for(int i=0;i<s.size();i++)
    if(s[i][col]==num)
      return false;

  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if(s[(row-row%3)+i][(col-col%3)+j]==num)
        return false;

  return true;
}
bool to_fill(vector<vector<int> >s,int &row,int &col)
{
  for(row=0;row<s.size();row++)
    for(col=0;col<s.size();col++)
      if(s[row][col]==0)
        return true;

    return false;
}
bool solve(vector<vector<int> >&s)
{
  int row,col;
  if(!to_fill(s,row,col))
    return true;

  for(int i=1;i<=9;i++)
  {
    if(is_safe(s,row,col,i))
    {
      s[row][col]=i;
      if(solve(s))
        return true;
      s[row][col]=0;
    }
  }
  return false;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<int> > s(9,vector<int>(9,0));
  for(int i=0;i<s.size();i++)
    for(int j=0;j<s.size();j++)
      cin>>s[i][j];

  cout<<endl;
  if(solve(s))
    for(int i=0;i<s.size();i++)
    {
      for(int j=0;j<s.size();j++)
      {
        cout<<s[i][j]<<" ";
      }
      cout<<endl;
    }
  else
    cout<<"No Solution "<<endl;
  return 0;
}
