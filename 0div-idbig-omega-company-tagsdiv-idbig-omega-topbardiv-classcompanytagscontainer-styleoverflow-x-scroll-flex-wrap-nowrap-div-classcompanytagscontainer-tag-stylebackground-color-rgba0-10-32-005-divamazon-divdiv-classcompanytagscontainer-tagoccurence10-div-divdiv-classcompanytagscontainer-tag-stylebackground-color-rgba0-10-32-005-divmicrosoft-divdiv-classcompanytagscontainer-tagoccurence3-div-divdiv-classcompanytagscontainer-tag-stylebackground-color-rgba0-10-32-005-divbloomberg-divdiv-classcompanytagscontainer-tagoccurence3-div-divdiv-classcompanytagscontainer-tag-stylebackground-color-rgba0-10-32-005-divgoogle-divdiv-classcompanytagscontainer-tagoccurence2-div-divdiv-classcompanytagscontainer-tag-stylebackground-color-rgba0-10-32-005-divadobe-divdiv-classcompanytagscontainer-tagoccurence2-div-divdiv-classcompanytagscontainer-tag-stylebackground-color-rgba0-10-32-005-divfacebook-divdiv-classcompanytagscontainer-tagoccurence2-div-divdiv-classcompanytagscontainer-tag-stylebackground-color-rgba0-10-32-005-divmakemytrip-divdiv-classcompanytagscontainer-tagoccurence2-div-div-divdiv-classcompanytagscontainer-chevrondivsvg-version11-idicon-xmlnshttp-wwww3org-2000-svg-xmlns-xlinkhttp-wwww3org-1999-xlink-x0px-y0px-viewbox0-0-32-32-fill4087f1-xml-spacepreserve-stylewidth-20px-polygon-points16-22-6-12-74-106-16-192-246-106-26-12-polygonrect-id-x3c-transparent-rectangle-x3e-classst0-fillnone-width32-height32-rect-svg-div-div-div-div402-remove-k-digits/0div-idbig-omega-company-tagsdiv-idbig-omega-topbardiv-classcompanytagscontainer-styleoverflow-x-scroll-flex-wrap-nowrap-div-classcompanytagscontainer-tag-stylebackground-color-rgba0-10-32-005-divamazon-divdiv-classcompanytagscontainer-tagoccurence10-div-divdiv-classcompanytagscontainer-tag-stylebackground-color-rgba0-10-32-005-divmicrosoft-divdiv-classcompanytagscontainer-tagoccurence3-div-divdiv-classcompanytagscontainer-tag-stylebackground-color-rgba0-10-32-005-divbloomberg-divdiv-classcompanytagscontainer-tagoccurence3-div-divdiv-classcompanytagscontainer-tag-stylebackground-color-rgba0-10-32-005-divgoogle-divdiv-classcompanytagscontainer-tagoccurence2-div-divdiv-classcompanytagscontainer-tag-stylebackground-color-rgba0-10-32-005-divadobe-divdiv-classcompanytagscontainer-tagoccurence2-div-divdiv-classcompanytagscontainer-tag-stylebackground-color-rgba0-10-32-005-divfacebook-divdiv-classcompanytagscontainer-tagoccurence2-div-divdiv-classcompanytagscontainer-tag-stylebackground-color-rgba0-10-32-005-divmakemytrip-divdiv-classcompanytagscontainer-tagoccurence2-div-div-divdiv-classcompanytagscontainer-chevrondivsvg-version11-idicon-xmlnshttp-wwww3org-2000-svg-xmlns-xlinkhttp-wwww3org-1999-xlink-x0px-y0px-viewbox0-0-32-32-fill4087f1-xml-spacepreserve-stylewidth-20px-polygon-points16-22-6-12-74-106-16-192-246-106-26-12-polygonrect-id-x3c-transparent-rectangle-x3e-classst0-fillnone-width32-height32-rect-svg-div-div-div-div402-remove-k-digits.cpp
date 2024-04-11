class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char ch:num){
            while(!st.empty()&&ch<st.top()&&k){
                st.pop();///remove an element
                k--;
            }
            st.push(ch);
        }
        //if there are still any k to be removed
        while(k&&!st.empty()){
            k--;
            st.pop();
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        reverse(ans.begin(),ans.end());
        int start=0;
        while(start<ans.length()&&ans[start]=='0')
        start++;
        ans=ans.substr(start);
        return (ans=="")?"0":ans;
    }
};
