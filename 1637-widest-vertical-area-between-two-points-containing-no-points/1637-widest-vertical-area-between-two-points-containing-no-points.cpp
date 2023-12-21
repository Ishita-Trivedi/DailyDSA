class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int maxi=0;
        for(int i=1;i<points.size();i++){
            int x=points[i][0];
            int prev=points[i-1][0];
            maxi=max(maxi,x-prev);
        }
        return maxi;
    }
};