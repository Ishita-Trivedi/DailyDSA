class Solution {
public:
    string customSortString(string order, string s) {
       unordered_map<char,int>mp;
       string ans="";
       for(char ch:s)
       mp[ch]++;
       for(char ch:order){
           string temp="";
           while(mp[ch]){
                temp+=ch;
                mp[ch]--;
               }  
           if(mp.find(ch)!=mp.end()){
                ans+=temp;            
           }
       }
       for(auto x:mp){
           string temp="";
           char ch=x.first;
           while(mp[ch]){
                temp+=ch;
                mp[ch]--;
               } 
               ans+=temp;
       }
       return ans; 
    }
};