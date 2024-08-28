class Solution {
typedef pair<int,int>p;
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0&&j>=0&&i<m&&j<n;
    }
    bool bfs(int i,int j,vector<vector<int>>&grid,
    vector<vector<int>>& carpet){
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        queue<p>q;
        int m=grid.size(),n=grid[0].size();

        grid[i][j]=-1;
        q.push({i,j});

        bool valid=true;

        while(!q.empty()){
            auto t=q.front();q.pop();
            int i=t.first,j=t.second;
             valid=valid&&(carpet[i][j]==1);
            for(int k=0;k<4;k++){
            int kx=x[k]+i,ky=y[k]+j;
            if(isValid(kx,ky,m,n)&&grid[kx][ky]==1){
                grid[kx][ky]=-1;
                q.push({kx,ky});
            }
            }
        }
        return valid;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size(),n=grid2[0].size(),count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    if(bfs(i,j,grid2,grid1))
                    count++;
                }
            }
        }
        return count;
    }
};