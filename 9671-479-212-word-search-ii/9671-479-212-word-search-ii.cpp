class TrieNode{
    public:
    char data;
    bool isTerminal;//words unique so used bool else int
    TrieNode* children[26];
    TrieNode(char d){
        data=d;
        for(int i=0;i<26;i++)
        children[i]=nullptr;
        isTerminal=false;
    }
};
class Solution {
public:
    TrieNode* root;
    int m,n;
    void insertWord(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int idx=word[0]-'a';
        TrieNode* child;
        if(root->children[idx])
        child=root->children[idx];
        else{
            TrieNode* newChild=new TrieNode(word[0]);
            root->children[idx]=newChild;
            child=newChild;
        }
        return insertWord(child,word.substr(1));
    }
    void searchAllWords(int i,int j,TrieNode* root,string word,vector<vector<int>>&vis,vector<string>&ans,vector<vector<char>>& board){
         if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || !root->children[board[i][j] - 'a'])
            return;
        
        root = root->children[board[i][j] - 'a'];
        word += board[i][j];

        if (root->isTerminal) {
            ans.push_back(word);
            root->isTerminal = false; // Prevent duplicates
        }

        vis[i][j] = 1;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            searchAllWords(x, y, root, word, vis, ans, board);
        }

        vis[i][j] = 0; // Backtrack
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        m=board.size();
        n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        root=new TrieNode('\0');
        for(string word:words)
        insertWord(root,word);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(root->children[board[i][j]-'a'])
                searchAllWords(i,j,root,"",vis,ans,board);
            }
        }
        return ans;
    }
};