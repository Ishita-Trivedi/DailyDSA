class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,m=g.size(),n=s.size(),count=0;
        while(j<n&&i<m){
            if(s[j]>=g[i]){
                count++;
                i++;j++;
            }
            else
            j++;
        }
        return count;
    }
};