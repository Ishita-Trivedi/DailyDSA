class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size(),n=matrix[0].size(),l=0,h=(m*n)-1;
        while(l<=h){
            int mid=(l+h)/2,r=mid/n,c=mid%n;
            if(matrix[r][c]==target)return true;
            else if(target>matrix[r][c])l=mid+1;
            else
            h=mid-1;
        }
        return false;
    }
};