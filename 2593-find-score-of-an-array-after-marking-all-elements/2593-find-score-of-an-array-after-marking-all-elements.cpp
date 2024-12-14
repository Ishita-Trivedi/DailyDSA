class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        long long score=0;
        vector<int>vis(n,0);
        vector<vector<int>>vec;
        for(int i=0;i<n;i++)
        vec.push_back({nums[i],i});
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            int idx=vec[i][1];
            if(vis[idx])continue;
            score+=vec[i][0];
            vis[idx]=1;
            if(idx>0)
            vis[idx-1]=1;
            if(idx<n-1)
            vis[idx+1]=1;
        }
        return score;
    }
};