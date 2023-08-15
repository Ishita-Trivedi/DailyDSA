class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<int>prev(m+1,0);
        //to make both equal
        for(int i=0;i<n+1;i++){
            vector<int>curr(m+1,0);//all will be curr[j] no i
            for(int j=0;j<m+1;j++){
                if(i==0)curr[j]=j;//insert all j as word1 empty
                else if(j==0)curr[j]=i;//delete all i as word2 empty
                else if(word1[i-1]==word2[j-1])
                curr[j]=prev[j-1];
                else{
                int in=1+curr[j-1];//insert hypothetically
                int del=1+prev[j];//not present move back
                int rep=1+prev[j-1];//matched move back all
                curr[j]=min({in,del,rep});
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};