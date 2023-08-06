class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>mp;
        for(string s:strs){
            vector<int>freq(26,0);
            for(int i=0;i<s.length();i++)
            freq[s[i]-97]++;
            mp[freq].push_back(s);
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};