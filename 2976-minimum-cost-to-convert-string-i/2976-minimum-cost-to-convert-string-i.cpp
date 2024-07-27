class Solution {
public:
    typedef long long ll;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>>adj(26,vector<ll>(26,LLONG_MAX));
        int ns=original.size();
        ll ans=0;
        for(int i=0;i<ns;i++){
            int u=original[i]-'a',v=changed[i]-'a';
            if(cost[i]<adj[u][v])
            adj[u][v]=cost[i]*1LL;
        }
        for(int i=0;i<26;i++)
        adj[i][i]=0;
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(adj[i][k]==LLONG_MAX||adj[k][j]==LLONG_MAX)continue;
                    ll val=adj[i][k]+adj[k][j];
                    if(val<adj[i][j])
                    adj[i][j]=val;
                }
            }
        }
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                int u=source[i]-'a',v=target[i]-'a';
                if(adj[u][v]==LLONG_MAX)return -1;
                ans+=adj[u][v];
            }
        }
        return ans;
    }
};