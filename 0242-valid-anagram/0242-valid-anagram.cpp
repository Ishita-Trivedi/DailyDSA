class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto ch:s)
        mp[ch]++;
        for(auto ch :t){
            if(mp.find(ch)==mp.end())return false;
            mp[ch]--;
            if(mp[ch]<1)mp.erase(ch);
        }
        return mp.empty();
    }
};