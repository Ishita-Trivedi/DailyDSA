/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root,int parent,unordered_map<int,vector<int>>&adj){
        if(!root)return;
        vector<int>&curr=adj[root->val];
        if(parent!=0)curr.push_back(parent);
        if(root->left)curr.push_back(root->left->val);
        if(root->right)curr.push_back(root->right->val);
        dfs(root->left,root->val,adj);
        dfs(root->right,root->val,adj);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        //create level chunks using bfs but require adjacency list
        unordered_map<int,vector<int>>adj;
        dfs(root,0,adj);
        queue<int>q;
        unordered_set<int>visited;//as now it is a graph so track visited
        q.push(start);visited.insert(start);
        int minutes=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
         int n=q.front();q.pop();//we iterate as values not TreeNode now
                for(int child:adj[n]){
                    if(visited.find(child)==visited.end()){//unvisited
                        visited.insert(child);
                        q.push(child);
                    }
                }
            }
            minutes++;//as next set of chunk of nodes
        }
        return --minutes;//as we counted the start chunk also
    }
};