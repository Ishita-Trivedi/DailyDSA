class Solution {
public:
    int minimumLength(string s) {
        int i=0,n=s.length(),j=n-1;
        if(s[i]!=s[j])return n;
        while(s[i]==s[j]&&i<j){
            if(i+1<j&&s[i+1]==s[j])i++;
            else if(j-1>i&&s[i]==s[j-1])j--;
            else{
                i++;
                j--;
            }
        }
        return j-i+1;
    }
};