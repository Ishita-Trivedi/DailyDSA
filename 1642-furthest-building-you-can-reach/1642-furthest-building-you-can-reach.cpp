class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=heights.size();
        for(int i=0;i<n-1;i++){
            int jump=heights[i+1]-heights[i];
            if(jump>0)pq.push(jump);
            if(pq.size()>ladders){
                bricks-=pq.top();pq.pop();
            }
            if(bricks<0)return i;
        }
        return heights.size()-1;
    }
};