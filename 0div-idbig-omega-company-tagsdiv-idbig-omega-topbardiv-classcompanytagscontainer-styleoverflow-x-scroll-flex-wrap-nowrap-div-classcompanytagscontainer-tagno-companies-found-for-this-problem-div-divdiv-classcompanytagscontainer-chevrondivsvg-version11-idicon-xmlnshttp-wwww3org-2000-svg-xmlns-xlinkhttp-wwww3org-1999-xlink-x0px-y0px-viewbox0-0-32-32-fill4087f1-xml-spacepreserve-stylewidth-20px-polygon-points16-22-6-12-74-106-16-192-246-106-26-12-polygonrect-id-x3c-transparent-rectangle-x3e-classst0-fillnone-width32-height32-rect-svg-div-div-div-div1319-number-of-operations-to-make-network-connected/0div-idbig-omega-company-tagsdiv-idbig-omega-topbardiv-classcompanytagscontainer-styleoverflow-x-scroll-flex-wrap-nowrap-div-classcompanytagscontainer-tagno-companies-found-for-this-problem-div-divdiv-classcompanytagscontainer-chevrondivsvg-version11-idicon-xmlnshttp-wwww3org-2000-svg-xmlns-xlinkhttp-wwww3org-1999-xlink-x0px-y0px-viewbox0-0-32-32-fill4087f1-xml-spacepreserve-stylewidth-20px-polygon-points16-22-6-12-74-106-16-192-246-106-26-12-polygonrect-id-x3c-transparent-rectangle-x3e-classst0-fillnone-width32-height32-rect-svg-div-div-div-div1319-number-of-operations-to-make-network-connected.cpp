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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0,comp=0;
        for(auto vec:connections){
            int u=vec[0],v=vec[1];
              int ultp_u=ds.findParent(u);
                int ultp_v=ds.findParent(v);
                if(ultp_u==ultp_v)extra++;
                else
                ds.unionByRank(u,v);
        }
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)comp++;
        }
        comp--;
        if(extra<comp)return -1;
        return comp;
    }
};