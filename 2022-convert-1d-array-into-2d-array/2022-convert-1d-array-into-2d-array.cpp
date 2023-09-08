class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n,0));
        if(original.size()>(m*n))return {};
        int x=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(x>=original.size())
                {return {};}
                ans[i][j]=original[x];x++;
            }
        }
        return ans;
    }
};