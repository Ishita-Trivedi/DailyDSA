class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length(),len=2;
        if(n<=2)return s;
        string ans=s.substr(0,2);
        for(int i=2;i<n;i++){
            if(ans[len-1]==s[i]&&ans[len-2]==s[i])
            continue;
            else{
                len++;
                ans+=s[i];
            }
        }
        return ans;
    }
};