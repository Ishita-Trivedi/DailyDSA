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
    TreeNode* construct(int ps,int pe,int ins,int ine,vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>&mp){
        if(pe<ps||ins>ine )return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=mp[root->val];
        int left=inroot-ins;
        root->left=construct(ps,ps+left-1,ins,inroot-1,inorder,postorder,mp);
        root->right=construct(ps+left,pe-1,inroot+1,ine,inorder,postorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;
        return construct(0,postorder.size()-1,0,inorder.size()-1,inorder,postorder,mp);
    }
};