class Solution {
private:
    int time(vector<int>& a,vector<int>& b){
        int sx=a[0], sy=a[1], dx=b[0], dy=b[1];
        return max(abs(sx-dx),abs(sy-dy));
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();i++)
        ans+=time(points[i-1],points[i]);
        return ans;
    }
};