class Solution {
public:
    int minimumDeletions(string s) {
        //b.....a del both b and a
        int cntb=0,cnta=0,n=s.length(),ans=n;
        for(int i=0;i<n;i++)
        cnta+=(s[i]=='a');
        
        for(char ch:s){
            cnta-=(ch=='a');
            ans=min(ans,cnta+cntb);
            cntb+=(ch=='b');
        }
        return ans;
    }
};