class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        for(char ch:allowed)st.insert(ch);
        int count=0;
        for(string s:words){
            bool ck=true;
            for(char ch:s){
                if(st.find(ch)==st.end()){
                    ck=false;break;
                }
            }
            if(ck)count++;
        }
        return count;
    }
};