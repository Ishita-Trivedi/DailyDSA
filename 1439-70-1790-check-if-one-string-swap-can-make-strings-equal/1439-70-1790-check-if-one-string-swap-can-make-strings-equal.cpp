class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int>mp;
        int cnt=0,n=s1.length();
        for(char ch:s1)
        mp[ch]++;
        for(int i=0;i<n;i++){
            if(mp.find(s2[i])==mp.end())
            return false;
            if(--mp[s2[i]]==0)
            mp.erase(s2[i]);
            if(s1[i]!=s2[i])cnt++;
        }
        return cnt<=2&&mp.size()==0;
    }
};