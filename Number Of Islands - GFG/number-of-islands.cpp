//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
public:
    vector<int>rank,parent,size;
    DisjointSet(int n){//defining the constructor for initialization
        rank.resize(n+1,0);//secure for 1 based index too
        parent.resize(n+1);
        size.resize(n + 1,1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    int findParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findParent(parent[node]);//path compression->storing on return 
    }
    void unionByRank(int u,int v){
        //ultp is ultimate parent
        int ultp_u=findParent(u);
        int ultp_v=findParent(v);
        if(ultp_u==ultp_v)return;//same parent then no change to be done
        if(rank[ultp_u]<rank[ultp_v]){
            parent[ultp_u]=ultp_v;//smaller attached to larger no increase of rank
        }
        else if(rank[ultp_v]<rank[ultp_u]){
            parent[ultp_v] = ultp_u;
        }
        else{//on same rank
            parent[ultp_v] = ultp_u;//attach any
            rank[ultp_u]++;
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        vector<int>ans;
        for(auto vec:operators){
            int i=vec[0],j=vec[1];
            if(vis[i][j])ans.push_back(count);
            else{
                vis[i][j]=1;count++;
                int node1=i*m+j;
                int x[]={-1,1,0,0};
                int y[]={0,0,1,-1};
                for(int k=0;k<4;k++){//checking adjacents
                    int ix=i+x[k],jy=j+y[k];
                    if((ix>=0&&ix<n)&&(jy>=0&&jy<m)){
                         int node2=ix*m+jy;//row*m+col
                         if(vis[ix][jy]){
                             //if ultimate parent not same make a connection else continue
                             if(ds.findParent(node1)==ds.findParent(node2))continue;
                             ds.unionByRank(node2,node1);count--;
                         }
                    }
                }
                ans.push_back(count);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends