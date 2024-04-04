class Solution {
public:
    int maxDepth(string s) {
        int open =0,ans=0;
        for(char ch:s){
            if(ch=='(')open++;
            else if(ch==')'){
                ans=max(ans,open);
                open--;
            }
        }
        return ans;
    }
};