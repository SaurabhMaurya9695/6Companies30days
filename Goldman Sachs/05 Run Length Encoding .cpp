#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s= "wwwwaaadexxxxxx";
    int n =  s.size();
    map<char , int > mp;
    for(int i = 0; i< n; i++)
    {
        mp[s[i]]++;
    }
    for(auto it : mp)
    {
        cout << it.first << it.second ;
    }
return 0 ;
}


////////
string encode(string s)
{     
 //Your code here
   string ans="";
   int i=0,j=0;
   while(j<s.length()){
       while(s[i]==s[j]){
           j++;
       }
       ans+=s[i] + to_string(j-i);
       i=j;
   }
   return ans;
}    