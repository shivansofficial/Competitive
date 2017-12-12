#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
bool is_safe(vector<vector<int> > b, int row, int col)
{
  for(int i=0;i<col;i++)
    if(b[row][i])
      return false;

  for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    if(b[i][j])
      return false;

  for(int i=row,j=col;i<b.size() && j>=0;i++,j--)
    if(b[i][j])
      return false;

  return true;
}
bool solve_queen(vector<vector<int> >&b,int col)
{
  if(col>=b.size())
    return true;

  for(int i=0;i<b.size();i++)
  {
    if(is_safe(b,i,col))
    {
      b[i][col]=1;
      if(solve_queen(b,col+1))
        return true;

      b[i][col]=0;
    }
  }
  return false;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector< vector<int> > b(n,vector<int>(n,0));
  
  if(solve_queen(b,0))
    for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          cout<<b[i][j]<<" ";
        }
        cout<<endl;
      }
  else
    cout<<"Not possible"<<endl;
  return 0;
}
