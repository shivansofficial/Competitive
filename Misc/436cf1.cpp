#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int t;
  map<int,int>dict;
  for(int i=0;i<n;i++)
  {
    cin>>t;
    dict[t]++;
  }
  map<int,int>::iterator it = dict.begin();
  map<int,int>::iterator it2 = it;
  map<int,int>::iterator itt = ++it;
  if(itt!=dict.end() && dict.size()==2)
  {
    if(it2->second == it->second)
    {
      cout<<"YES\n";
      cout<<it->first<<" "<<it2->first<<endl;
    }
    else
      cout<<"NO\n";
  }
  else
    cout<<"NO\n";
  return 0;
}
