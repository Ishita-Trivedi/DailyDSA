class Solution {
private:
    bool helper(int i,int j,int k,string& word,vector<vector<int>>& vis,vector<vector<char>>& board){
        if(k>=word.size())return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size())return false;
        if(board[i][j]!=word[k])return false;
        if(vis[i][j])return false;
        bool ans=false;vis[i][j]=1;
        ans=ans||helper(i+1,j,k+1,word,vis,board);
        ans=ans||helper(i,j+1,k+1,word,vis,board);
        ans=ans||helper(i-1,j,k+1,word,vis,board);
        ans=ans||helper(i,j-1,k+1,word,vis,board);
        vis[i][j]=0;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
       bool ans;
       for(int i=0;i<board.size();i++){
           for(int j=0;j<board[i].size();j++){
               if(board[i][j]==word[0])
               ans=helper(i,j,0,word,vis,board);
               if(ans)return true;
           }
       }
       return false;
    }
};