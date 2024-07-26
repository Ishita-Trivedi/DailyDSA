class Solution {
public:
    typedef long long ll;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(auto vec:edges){
            int u=vec[0],v=vec[1],wt=vec[2];
            adj[u][v]=adj[v][u]=wt;
        }
        for(int i=0;i<n;i++)
        adj[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    ll val=adj[i][k]+adj[k][j];
                    if(val<adj[i][j])
                    adj[i][j]=val;
                }
            }
        }
        int ans=-1,mini=1e9;
        for(int i=0;i<n;i++){
            int cnt=0;
           for(int j=0;j<n;j++){
            if(i==j)continue;
            if(adj[i][j]<=distanceThreshold )cnt++;
           }
            if(cnt<=mini){
                ans=i;
                mini=cnt;
            }
        }
       
        return ans;
    }
};