class Solution {
public:
    void detect(int m,int n,queue<pair<int,int>>&q,vector<vector<int>>&vis,vector<vector<char>>& board){
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;q.pop();
            int arx[]={-1,1,0,0};int ary[]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int x=arx[k]+i,y=ary[k]+j;
                if(x>=0&&x<m&&y>=0&&y<n){
                    if(board[x][y]=='O'&&!vis[x][y]){
                        q.push({x,y});vis[x][y]=-1;
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                if(board[i][j]=='O'){
                    vis[i][j]=-1;
                    q.push({i,j});
                }
                }
            }
        }
        detect(m,n,q,vis,board);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&!vis[i][j])board[i][j]='X';
            }
        }
    }
};