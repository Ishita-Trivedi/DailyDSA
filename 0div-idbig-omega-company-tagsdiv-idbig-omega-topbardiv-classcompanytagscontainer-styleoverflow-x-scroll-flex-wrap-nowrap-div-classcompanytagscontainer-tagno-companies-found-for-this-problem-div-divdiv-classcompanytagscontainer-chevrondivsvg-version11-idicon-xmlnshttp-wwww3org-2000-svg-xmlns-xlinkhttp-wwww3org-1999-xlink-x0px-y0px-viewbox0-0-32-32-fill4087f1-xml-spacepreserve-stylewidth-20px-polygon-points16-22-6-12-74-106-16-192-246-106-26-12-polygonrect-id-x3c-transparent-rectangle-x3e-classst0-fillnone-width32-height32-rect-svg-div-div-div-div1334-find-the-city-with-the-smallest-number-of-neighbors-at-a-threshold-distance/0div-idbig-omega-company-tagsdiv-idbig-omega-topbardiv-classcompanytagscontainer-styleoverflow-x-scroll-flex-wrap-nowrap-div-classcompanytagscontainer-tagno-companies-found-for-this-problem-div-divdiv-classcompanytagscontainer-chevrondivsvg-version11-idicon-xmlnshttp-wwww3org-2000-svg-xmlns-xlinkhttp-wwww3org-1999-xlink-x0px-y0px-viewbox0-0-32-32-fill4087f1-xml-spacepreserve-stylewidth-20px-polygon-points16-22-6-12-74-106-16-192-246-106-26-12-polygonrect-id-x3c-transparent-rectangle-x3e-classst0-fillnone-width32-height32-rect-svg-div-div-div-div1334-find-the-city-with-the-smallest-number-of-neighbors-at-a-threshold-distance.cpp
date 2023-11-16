class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
                             //using flyod warshall algo
  vector<vector<int>> matrix(n, vector<int>(n, 1e9));
    for(int i=0;i<n;i++)//diagonals
    matrix[i][i]=0;
    for(auto vec:edges){//UG to DG conversion
        int u=vec[0],v=vec[1],wt=vec[2];
        matrix[u][v]=wt;matrix[v][u]=wt;
    }
    //FWA
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    int max_count=n,node=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i==j)continue;//as this would always be zero
            if(matrix[i][j]<=distanceThreshold)count++;
        }
        if(count<=max_count){max_count=count;node=i;}
    }
    return node;
    }
};