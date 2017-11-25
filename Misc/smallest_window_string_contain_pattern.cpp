#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;
#define endl '\n'
const int no_of_char=256;
string sub_string(string s,string p)
{
  int len1=s.length();
  int len2=p.length();

  int hash_s[no_of_char]={0};
  int hash_p[no_of_char]={0};

  if (len1 < len2)
    {
        cout << "No such window exists"<<endl;
        return " ";
    }

  for(int i=0;i<len2;i++)
    hash_p[p[i]]++;

  int start=0,start_ind=-1,min_len=INT_MAX,count=0;

  for(int i=0;i<len1;i++)
  {
    hash_s[s[i]]++;

    if(hash_p[s[i]]!=0 && hash_s[s[i]]<=hash_p[s[i]])
      count++;

    if(count==len2)
    {
      while(hash_p[s[start]]==0 || hash_s[s[start]]>hash_p[s[start]])
        {
          if(hash_s[s[start]]>hash_p[s[start]])
            hash_s[s[start]]--;

          start++;
        }

      int len_window=i-start+1;

      if(len_window<min_len)
        {
          min_len=len_window;
          start_ind=start;
        }
    }
  }

  if(start_ind==-1)
  {
    cout<<"No such window "<<endl;
    return " ";
  }
  return s.substr(start_ind,min_len);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s,p;
  getline(cin,s);
  getline(cin,p);
  cout<<"Smallest window is : "<<sub_string(s,p);
  return 0;
}
