class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>copied(heights.begin(),heights.end());
        int cnt=0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(copied[i]!=heights[i])cnt++;
        }
        return cnt;
    }
};