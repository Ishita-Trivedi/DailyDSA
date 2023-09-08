class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,rows=matrix.size(),cols=matrix[0].size(),j=cols-1;
        while(i<rows&&j>=0){
            if(matrix[i][j]==target)return true;
            if(matrix[i][j]<target)i++;
            else
            j--;
        }
        return false;
    }
};