class Solution {
    string b;
private:
    void bfs(string& beginWord,string& endWord,unordered_set<string>&st,unordered_map<string,int>&mp){
        queue<string>q;
        q.push(beginWord);mp[beginWord]=1;st.erase(beginWord);
        while(!q.empty()){
                string word=q.front();q.pop();
                 int step=mp[word];
                 if(word==endWord)break;
                for(int j=0;j<word.length();j++){
                    char org=word[j];
                    for(char ch='a';ch<='z';ch++){
                        word[j]=ch;
                        if(st.count(word)>0){
                            st.erase(word);
                            q.push(word);
                            mp[word]=step+1;
                        }
                    }
                    word[j]=org;
                }
            }
    }
void dfs(string& word, vector<string>& temp, unordered_map<string, int>& mp, vector<vector<string>>& ans) {
    if (word == b) {
        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        reverse(temp.begin(), temp.end());//else recursive call disturbed
        return;
    }
    int steps = mp[word],len=word.length();
    for (int i = 0; i < len; i++) {
        char org = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++) {
            word[i] = ch;
            if (mp.find(word) != mp.end() && mp[word] + 1 == steps) {
                // implies word is of just lower level
                temp.push_back(word);
                dfs(word, temp, mp, ans);
                temp.pop_back();
            }
        }
        word[i] = org;
    }
}
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        vector<vector<string>>ans;vector<string>temp;
        unordered_set<string>st(wordList.begin(),wordList.end());
        unordered_map<string,int>mp;
        bfs(beginWord,endWord,st,mp);
        if(mp.find(endWord)!=mp.end()){
            temp.push_back(endWord);
            dfs(endWord,temp,mp,ans);
        }
        return ans;
    }
};