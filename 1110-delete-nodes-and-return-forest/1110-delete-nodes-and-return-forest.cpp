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
public:
    void dfs(TreeNode* root,unordered_set<int>&st,
     vector<TreeNode*>&ans,bool isRoot){
        if(!root)return ;
        //means to be deleted
        if(st.find(root->val)!=st.end()){
            dfs(root->left,st,ans,1);
            dfs(root->right,st,ans,1);
        }
        else{
            if(isRoot) ans.push_back(root);
            TreeNode* leftNode=root->left,
            *rightNode=root->right;
        if(root->left&&st.find(root->left->val)!=st.end())
            root->left=nullptr;
        if(root->right&&st.find(root->right->val)!=st.end())
            root->right=nullptr;
            dfs(leftNode,st,ans,0);
            dfs(rightNode,st,ans,0);
        }
     }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>delnodes(to_delete.begin(),to_delete.end());
        dfs(root,delnodes,ans,true);
        return ans;
    }
};