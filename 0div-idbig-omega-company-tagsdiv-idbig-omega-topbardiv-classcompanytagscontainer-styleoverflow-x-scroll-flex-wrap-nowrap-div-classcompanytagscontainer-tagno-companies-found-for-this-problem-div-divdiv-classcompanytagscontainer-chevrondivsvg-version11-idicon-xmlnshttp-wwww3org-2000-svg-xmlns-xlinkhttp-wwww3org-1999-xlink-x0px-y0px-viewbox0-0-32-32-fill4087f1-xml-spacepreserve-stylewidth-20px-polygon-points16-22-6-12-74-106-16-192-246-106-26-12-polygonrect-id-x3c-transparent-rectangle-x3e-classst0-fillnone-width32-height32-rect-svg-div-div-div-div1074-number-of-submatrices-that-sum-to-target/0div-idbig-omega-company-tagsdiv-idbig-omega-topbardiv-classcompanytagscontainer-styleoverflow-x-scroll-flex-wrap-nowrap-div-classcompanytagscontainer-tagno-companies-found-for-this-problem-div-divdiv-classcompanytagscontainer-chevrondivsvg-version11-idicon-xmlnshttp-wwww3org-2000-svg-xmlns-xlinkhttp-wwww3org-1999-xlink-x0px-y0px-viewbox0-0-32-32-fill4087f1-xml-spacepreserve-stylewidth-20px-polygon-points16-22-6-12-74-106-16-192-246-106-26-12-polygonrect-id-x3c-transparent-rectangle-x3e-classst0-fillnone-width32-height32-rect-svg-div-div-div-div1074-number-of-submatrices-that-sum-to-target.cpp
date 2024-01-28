class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        //prefix sum
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        for(int cs=0;cs<m;cs++){
            for(int ce=cs;ce<m;ce++){
                 int currsum=0;
                unordered_map<int,int>mp;mp[0]++;
                for(int rs=0;rs<n;rs++){
                    int rowsum=matrix[rs][ce]-(cs?matrix[rs][cs-1]:0);
                    currsum+=rowsum;
                    ans+=mp[currsum-target];
                    mp[currsum]++;
                }
            }
        }
        return ans;
    }
};