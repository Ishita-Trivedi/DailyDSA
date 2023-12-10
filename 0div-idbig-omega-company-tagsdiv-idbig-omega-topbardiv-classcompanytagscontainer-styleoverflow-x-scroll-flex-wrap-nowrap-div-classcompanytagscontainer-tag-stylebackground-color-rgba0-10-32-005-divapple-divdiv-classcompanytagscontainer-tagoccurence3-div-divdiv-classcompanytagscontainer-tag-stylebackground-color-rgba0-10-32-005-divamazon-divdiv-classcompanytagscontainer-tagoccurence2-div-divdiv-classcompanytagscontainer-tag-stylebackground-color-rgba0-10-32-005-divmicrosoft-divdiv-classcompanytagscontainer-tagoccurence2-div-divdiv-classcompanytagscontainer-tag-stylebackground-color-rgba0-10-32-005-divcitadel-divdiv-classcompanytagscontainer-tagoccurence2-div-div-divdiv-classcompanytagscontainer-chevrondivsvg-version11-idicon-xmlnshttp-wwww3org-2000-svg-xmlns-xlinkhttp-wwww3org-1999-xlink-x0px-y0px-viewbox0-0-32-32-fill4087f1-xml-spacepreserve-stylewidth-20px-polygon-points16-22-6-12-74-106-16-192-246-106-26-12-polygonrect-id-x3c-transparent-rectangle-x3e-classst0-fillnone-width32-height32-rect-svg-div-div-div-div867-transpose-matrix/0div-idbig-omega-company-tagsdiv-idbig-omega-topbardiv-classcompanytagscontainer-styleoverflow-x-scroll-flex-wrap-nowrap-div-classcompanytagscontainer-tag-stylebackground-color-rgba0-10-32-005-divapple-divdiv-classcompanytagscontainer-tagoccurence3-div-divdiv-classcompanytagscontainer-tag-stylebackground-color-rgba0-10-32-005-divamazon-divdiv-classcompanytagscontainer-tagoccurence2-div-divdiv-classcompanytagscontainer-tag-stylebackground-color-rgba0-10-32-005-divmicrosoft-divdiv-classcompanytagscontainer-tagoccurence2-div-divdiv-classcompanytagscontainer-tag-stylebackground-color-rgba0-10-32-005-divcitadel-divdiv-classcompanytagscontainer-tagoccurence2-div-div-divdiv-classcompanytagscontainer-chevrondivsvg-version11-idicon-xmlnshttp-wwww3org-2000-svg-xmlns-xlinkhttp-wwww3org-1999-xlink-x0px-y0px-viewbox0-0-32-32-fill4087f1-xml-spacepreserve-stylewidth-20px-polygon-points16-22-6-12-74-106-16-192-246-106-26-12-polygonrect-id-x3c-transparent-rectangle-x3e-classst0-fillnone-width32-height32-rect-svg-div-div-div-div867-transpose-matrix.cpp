class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r1=matrix.size(),c1=matrix[0].size(),r2=c1,c2=r1;
        vector<vector<int>>ans(r2,vector<int>(c2,0));
        for(int i=0;i<r2;i++){
            for(int j=0;j<c2;j++){
            ans[i][j]=matrix[j][i];
            }
        }
        return ans;
    }
};
