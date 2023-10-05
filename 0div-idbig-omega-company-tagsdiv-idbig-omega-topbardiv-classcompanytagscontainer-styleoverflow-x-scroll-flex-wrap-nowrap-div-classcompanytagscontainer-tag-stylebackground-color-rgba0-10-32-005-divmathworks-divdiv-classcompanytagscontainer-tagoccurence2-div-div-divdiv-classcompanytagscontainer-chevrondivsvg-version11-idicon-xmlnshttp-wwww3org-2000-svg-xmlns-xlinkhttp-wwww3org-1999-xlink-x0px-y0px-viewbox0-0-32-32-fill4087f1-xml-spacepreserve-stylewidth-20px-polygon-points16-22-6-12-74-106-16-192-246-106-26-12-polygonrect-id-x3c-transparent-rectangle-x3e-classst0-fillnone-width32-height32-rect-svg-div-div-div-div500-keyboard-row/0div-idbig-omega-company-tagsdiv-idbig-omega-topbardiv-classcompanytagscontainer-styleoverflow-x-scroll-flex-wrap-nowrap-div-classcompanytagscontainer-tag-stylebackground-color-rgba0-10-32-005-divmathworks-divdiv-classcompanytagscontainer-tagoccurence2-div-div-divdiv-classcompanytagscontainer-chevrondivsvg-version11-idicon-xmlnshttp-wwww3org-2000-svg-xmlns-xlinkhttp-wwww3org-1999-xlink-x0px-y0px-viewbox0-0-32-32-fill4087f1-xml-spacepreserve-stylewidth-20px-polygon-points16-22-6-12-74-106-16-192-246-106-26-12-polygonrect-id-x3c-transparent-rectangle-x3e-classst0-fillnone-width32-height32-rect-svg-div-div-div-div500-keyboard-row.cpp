#include <bits/stdc++.h> 
class Solution {
public:
    bool cando(string have,string s){
        for(char ch:s){
            bool found=false;
            for(char x:have){
                if(tolower(ch)==x){
                    found=true;break;
                }
            }
            if(!found)return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string>ans;
        for(string s:words){
 if(cando("qwertyuiop",s)||cando("asdfghjkl",s)||cando("zxcvbnm",s))
            ans.push_back(s);
        }
        return ans;
    }
};