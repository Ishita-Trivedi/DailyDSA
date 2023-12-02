class Solution {
private:
    bool check(string word,unordered_map<char,int>&mp){
        unordered_map<char,int>wordmp;
        for(auto ch:word){
            wordmp[ch]++;
            if(mp[ch]<wordmp[ch])return false;
        }
        return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum=0;unordered_map<char,int>mp;
        for(char ch:chars)
        mp[ch]++;
        for(string word:words){
            if(check(word,mp))
            sum+=word.length();
        }
        return sum;
    }
};