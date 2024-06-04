class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int o=0,e=0;
        for(char ch:s)
        mp[ch]++;
        for(auto x:mp){
            int f=x.second;
            e+=f/2;
            if(f&1)o++;
        }
        // return e*2+(o>=1)?1:0;
        return (e*2+((o>=1)?1:0));
    }
};