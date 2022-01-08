// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
// https://leetcode.com/problems/decode-string/
class Solution {
public:
    string decodeString(string s) {
        int currNo=0;
       string currString="";
       int prevNo;
       string prevString;
       stack<string>stringstack;
       stack<int>numstack;
       for(int i=0;i<s.size();i++)
       {
           if(isdigit(s[i])) currNo = currNo*10 + (s[i]-'0');
           if(isalpha(s[i])) currString += s[i];
           if(s[i] == '[')
           {
               stringstack.push(currString);
               numstack.push(currNo);
               currNo=0;
               currString="";
           }
           if(s[i] == ']')
           {
               prevNo = numstack.top();
               numstack.pop();
               prevString = stringstack.top();
               stringstack.pop();
               
               while(prevNo--)
               {
                  prevString += currString;
               }
               currString = prevString;
           }
       }
       return currString;
    }
};


// **************************************************************
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string num = "";
        string cur = "";
        for(char c:s){
            if(c=='['){
                st.push(num);
                st.push(cur);
                num = "";
                cur = "";
            }else if(c==']'){
                string temps = st.top();
                st.pop();
                string tempn = st.top();
                st.pop();
                cur = temps + repeat(cur,stoi(tempn));
            }else if(isdigit(c)){
                num += c;
            }else{
                cur += c;
            }
        }
        return cur;
    }
    
    string repeat(string s,int n){
        string ans = "";
        for(int i=0;i<n;i++){
            ans = ans+s;
        }
        return ans;
    }
};