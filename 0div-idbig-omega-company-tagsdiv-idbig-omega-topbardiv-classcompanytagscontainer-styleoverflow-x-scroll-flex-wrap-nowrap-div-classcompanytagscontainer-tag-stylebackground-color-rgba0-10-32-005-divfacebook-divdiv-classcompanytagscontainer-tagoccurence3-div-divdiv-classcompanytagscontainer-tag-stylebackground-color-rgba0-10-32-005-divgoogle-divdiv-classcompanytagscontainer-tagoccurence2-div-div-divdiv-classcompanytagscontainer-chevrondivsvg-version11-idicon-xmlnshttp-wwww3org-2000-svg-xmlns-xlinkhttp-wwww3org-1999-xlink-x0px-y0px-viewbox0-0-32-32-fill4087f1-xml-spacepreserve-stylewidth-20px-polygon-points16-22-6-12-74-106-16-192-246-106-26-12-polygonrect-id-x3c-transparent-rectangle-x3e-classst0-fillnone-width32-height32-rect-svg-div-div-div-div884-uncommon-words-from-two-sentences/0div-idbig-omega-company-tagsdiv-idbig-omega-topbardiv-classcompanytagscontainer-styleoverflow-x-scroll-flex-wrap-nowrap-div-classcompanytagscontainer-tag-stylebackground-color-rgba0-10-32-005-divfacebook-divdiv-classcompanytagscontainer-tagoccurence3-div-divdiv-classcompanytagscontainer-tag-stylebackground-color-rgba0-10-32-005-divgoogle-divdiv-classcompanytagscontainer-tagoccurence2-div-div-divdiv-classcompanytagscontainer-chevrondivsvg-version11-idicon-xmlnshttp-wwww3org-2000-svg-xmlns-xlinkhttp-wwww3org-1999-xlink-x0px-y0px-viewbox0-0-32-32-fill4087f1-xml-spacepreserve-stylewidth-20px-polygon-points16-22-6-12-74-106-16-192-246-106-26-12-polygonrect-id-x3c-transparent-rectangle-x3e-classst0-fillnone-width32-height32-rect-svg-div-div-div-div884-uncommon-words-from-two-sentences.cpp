class Solution {
public:
    void extraction(string word,map<string,int>&mp){
        word+=" ";
        stringstream s(word);
        string str;
        while(getline(s,str,' ')){
            mp[str]++;
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        map<string,int>mp;
        extraction(s1,mp);
        extraction(s2,mp);
        for(auto const& [s,cnt]:mp){
            if(cnt==1)
            ans.push_back(s);
        }
        return ans;
    }
};