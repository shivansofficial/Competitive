#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define endl '\n'
int lps(char* seq)
{ int n=strlen(seq);
  int l[n][n];
  for (int i = 0; i <n; i++) {
    l[i][i]=1;}

  int cl;
  for(int cl=2;cl<=n;cl++){
  for (int i = 0; i <n-cl+1; i++) {
    int j=i+cl-1;
    if(seq[i]==seq[j]&& cl==2) l[i][j]=2;
    else if (seq[i]==seq[j]) l[i][j]=l[i+1][j-1]+2;
    else l[i][j]=max(l[i+1][j],l[i][j-1]);
  }
  }
  return l[0][n-1];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  char seq[] = "GEEKS FOR GEEKS";
  int n = strlen(seq);
  cout<<"The lnegth of the LPS is "<< lps(seq)<<endl;
  return 0;
}
