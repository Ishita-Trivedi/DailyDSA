class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(char ch:s){
            if(!st.empty()&&ch!=st.top()&&(tolower(ch)==tolower(st.top())||
            toupper(ch)==toupper(st.top())))
           { st.pop();continue;}
           st.push(ch);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};