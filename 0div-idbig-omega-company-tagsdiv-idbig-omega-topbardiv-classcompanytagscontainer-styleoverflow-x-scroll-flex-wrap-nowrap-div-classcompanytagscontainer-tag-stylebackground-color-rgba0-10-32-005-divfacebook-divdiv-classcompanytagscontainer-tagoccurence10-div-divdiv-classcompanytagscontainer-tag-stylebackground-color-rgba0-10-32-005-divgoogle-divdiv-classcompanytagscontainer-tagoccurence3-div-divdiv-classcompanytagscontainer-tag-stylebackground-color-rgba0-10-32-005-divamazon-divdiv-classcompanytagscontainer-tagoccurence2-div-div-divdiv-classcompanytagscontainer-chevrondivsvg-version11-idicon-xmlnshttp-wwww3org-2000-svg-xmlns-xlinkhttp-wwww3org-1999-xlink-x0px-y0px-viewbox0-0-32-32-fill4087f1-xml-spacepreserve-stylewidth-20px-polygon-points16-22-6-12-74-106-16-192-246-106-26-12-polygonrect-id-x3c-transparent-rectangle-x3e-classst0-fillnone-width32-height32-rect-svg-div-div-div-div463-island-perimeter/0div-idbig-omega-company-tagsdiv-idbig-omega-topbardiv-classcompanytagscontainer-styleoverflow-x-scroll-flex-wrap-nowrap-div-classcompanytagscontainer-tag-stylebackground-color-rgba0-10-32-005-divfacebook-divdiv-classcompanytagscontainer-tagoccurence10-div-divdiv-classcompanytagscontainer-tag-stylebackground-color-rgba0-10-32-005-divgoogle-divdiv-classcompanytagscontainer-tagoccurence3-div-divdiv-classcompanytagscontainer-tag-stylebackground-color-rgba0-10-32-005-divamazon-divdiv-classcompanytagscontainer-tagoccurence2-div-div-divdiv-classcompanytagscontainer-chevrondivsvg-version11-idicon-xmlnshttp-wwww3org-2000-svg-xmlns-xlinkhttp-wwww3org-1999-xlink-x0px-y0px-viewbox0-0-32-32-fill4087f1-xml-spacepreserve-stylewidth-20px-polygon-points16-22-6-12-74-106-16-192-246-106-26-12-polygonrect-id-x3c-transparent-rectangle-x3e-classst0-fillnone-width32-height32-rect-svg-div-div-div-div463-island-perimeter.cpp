class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),count=0;
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                int c=0;
                for(int k=0;k<4;k++){
                    int kx=x[k]+i,ky=y[k]+j;
                    if(kx>=0&&kx<n&&ky>=0&&ky<m&&grid[kx][ky])c++;
                }
                count+=4-c;
                }
            }
        }
        return count;
    }
};