class Solution {
public:
    bool match(char ch1,char ch2){
        return ch1=='['&&ch2==']';
    }
    int minSwaps(string s) {
        stack<char>st;
        int count=0;
        for(char &ch:s){
           if(!st.empty()&&match(st.top(),ch))
           st.pop();
           else
           st.push(ch);
        }
        count=(st.size()/2+1)/2;
        return count;
    }
};