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
    bool helper(long long mini,long long maxi,TreeNode* root){
        if(!root)return true;
        if(root->val<=mini||root->val>=maxi)return false;
        return helper(mini,root->val,root->left)
        &&      helper(root->val,maxi,root->right);
    }
    bool isValidBST(TreeNode* root) {
        return helper(LLONG_MIN,LLONG_MAX,root);
    }
};