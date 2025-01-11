class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k)return false;
        unordered_map<char,int>mp;
        for(char ch:s)mp[ch]++;
        for(auto x:mp){
            if(x.second&1)k--;
        }
        return k>=0;
    }
};
