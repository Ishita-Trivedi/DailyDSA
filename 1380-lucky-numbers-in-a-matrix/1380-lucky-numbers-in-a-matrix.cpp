class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
         vector<int>arr;
        for(auto vec:matrix){
            int c=0;
            for(int i=1;i<vec.size();i++){
                if(vec[c]>vec[i])
                c=i;
            }
            int ans=-1e9,mini=vec[c];
           for(int r=0;r<matrix.size();r++)
           ans=max(ans,matrix[r][c]);
           if(ans==mini)
           arr.push_back(ans);
        }
        return arr;
    }
};