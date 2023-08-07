class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_set<char>st;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                if(st.find(t[i])==st.end()){
                mp[s[i]]=t[i];
                st.insert(t[i]);
                }
                else
                return false;
            }
        }
        string tf="";
        for(char ch:s){
            tf+=mp[ch];
        }
        return tf==t;
    }
};