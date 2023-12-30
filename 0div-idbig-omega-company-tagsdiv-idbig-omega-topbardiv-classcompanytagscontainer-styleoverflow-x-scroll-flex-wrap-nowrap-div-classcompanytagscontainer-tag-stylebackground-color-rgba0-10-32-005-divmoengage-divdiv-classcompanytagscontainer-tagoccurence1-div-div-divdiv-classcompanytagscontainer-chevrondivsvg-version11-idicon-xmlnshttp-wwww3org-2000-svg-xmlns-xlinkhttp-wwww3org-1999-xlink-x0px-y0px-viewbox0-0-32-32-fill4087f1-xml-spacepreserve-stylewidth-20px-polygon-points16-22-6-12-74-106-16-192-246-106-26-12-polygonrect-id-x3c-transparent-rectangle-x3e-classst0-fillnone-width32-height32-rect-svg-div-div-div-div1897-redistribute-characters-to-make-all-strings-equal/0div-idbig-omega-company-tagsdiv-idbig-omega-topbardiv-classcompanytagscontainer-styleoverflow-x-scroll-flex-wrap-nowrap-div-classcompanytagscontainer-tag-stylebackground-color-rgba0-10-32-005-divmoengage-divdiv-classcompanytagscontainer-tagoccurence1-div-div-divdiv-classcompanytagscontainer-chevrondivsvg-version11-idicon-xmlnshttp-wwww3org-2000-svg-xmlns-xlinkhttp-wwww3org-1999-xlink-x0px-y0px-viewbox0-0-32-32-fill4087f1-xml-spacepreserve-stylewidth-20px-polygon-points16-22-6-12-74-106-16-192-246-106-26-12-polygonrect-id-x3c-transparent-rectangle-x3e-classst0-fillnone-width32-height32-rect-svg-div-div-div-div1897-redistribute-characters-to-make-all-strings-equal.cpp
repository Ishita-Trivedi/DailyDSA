class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>mp;
        int n=words.size();
        for(string s:words){
            for(char ch:s)
            mp[ch]++;
        }
        for(auto x:mp){
            if(x.second %n !=0)return false;
        }
        return true;
    }
};