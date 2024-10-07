class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(char ch:s){
                if(!st.empty()&&ch=='B'&&st.top()=='A')
                st.pop();
                else if(!st.empty()&&ch=='D'&&st.top()=='C')
                st.pop();
                else
                st.push(ch);
        }
        return st.size();
    }
};