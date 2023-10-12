class Solution {
public:
    void dfs(int start,int n,vector<vector<int>>& isConnected,vector<int>&vis){
        vis[start]=1;
        for(int j=0;j<n;j++){
            int x=isConnected[start][j];
            if(x&&!vis[j])dfs(j,n,isConnected,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,n,isConnected,vis);
            }
        }
        return count;
    }
};