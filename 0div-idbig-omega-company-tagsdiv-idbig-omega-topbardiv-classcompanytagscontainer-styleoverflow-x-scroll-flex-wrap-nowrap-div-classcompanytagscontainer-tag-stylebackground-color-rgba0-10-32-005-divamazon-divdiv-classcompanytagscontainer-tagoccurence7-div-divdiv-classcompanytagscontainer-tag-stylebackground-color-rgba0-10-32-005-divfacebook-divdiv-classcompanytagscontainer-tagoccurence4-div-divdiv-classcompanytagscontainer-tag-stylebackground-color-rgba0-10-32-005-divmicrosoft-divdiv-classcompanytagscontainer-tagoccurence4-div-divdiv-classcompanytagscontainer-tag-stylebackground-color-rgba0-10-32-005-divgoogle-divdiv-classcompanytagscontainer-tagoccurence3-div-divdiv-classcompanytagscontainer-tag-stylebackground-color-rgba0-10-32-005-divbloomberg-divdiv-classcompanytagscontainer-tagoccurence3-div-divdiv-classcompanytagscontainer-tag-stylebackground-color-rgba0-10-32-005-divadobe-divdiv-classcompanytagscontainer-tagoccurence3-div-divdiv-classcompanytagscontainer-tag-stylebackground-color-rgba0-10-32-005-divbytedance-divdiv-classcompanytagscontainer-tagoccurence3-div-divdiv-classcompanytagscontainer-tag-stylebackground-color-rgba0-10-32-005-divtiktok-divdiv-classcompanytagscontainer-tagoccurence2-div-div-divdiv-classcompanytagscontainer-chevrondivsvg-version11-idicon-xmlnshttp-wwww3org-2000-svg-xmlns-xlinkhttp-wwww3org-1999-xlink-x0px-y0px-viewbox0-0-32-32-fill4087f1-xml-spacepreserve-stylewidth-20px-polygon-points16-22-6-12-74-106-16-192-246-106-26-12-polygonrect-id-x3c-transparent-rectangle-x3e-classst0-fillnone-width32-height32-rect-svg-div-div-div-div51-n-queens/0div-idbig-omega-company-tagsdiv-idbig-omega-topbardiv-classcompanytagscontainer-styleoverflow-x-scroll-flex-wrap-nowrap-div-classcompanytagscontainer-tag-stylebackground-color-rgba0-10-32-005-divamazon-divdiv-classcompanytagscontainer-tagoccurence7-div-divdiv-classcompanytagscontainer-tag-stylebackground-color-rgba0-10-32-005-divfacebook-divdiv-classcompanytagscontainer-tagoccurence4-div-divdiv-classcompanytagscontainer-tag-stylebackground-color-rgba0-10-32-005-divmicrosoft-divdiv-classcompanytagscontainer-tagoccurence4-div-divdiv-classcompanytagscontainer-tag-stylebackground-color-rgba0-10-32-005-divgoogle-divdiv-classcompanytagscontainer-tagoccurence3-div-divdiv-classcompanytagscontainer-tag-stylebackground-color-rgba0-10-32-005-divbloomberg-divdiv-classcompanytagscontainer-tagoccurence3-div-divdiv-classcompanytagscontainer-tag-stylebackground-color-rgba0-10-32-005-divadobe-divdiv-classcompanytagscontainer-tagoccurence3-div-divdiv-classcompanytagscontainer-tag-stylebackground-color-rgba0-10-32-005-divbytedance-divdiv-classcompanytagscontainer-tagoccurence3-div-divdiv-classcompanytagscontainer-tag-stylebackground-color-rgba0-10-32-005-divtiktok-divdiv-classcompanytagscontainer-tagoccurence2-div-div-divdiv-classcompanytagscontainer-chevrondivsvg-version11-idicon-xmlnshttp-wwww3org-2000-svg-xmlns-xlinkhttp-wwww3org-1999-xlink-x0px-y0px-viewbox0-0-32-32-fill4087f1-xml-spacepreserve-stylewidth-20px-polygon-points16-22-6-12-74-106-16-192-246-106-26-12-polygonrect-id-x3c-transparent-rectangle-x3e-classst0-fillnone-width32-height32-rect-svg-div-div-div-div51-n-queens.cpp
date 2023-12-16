class Solution {
private:
    bool isSafe(int i,int j,vector<string>&path){
        //no left check as we place only one queen per row
        //above 
        for(int row=0;row<=i;row++){
            if(path[row][j]=='Q')return false;
        }
        int row=i,col=j,n=path.size();
        while(row>=0&&col<n){
            if(path[row][col]=='Q')return false;
            row--;col++;
        }
        row=i;col=j;
        while(row>=0&&col>=0){
            if(path[row][col]=='Q')return false;
            row--;col--;
        }
        return true;
    }
    void helper(int row,int n, vector<string>&path,vector<vector<string>>&board){
        if(row>=n){
            board.push_back(path);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row,col,path)){
                path[row][col]='Q';
                helper(row+1,n,path,board);
                path[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=1;i<=n;i++)s+=".";
        vector<string>path(n,s);
         vector<vector<string>>board;
         helper(0,n,path,board);
         return board;
    }
};