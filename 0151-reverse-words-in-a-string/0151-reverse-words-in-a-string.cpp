class Solution {
public:
    string trim(string s){
        int i=0,end=s.length()-1;
        while(i<s.length()&&s[i]==' ')i++;
        while(end>=0&&s[end]==' ')end--;
        string ans="";
        while(i<=end){
            ans+=s[i];i++;
        }
        return ans;
    }
    string reverseWords(string s) {
        string ans="",word="";
        s=trim(s);
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                ans=" "+word+ans;
                word="";
                while(i<s.length()&&s[i]==' ')i++;
                i--;
            }
            else 
            word+=s[i];
        }
        ans=word+ans;
        return trim(ans);
    }
};