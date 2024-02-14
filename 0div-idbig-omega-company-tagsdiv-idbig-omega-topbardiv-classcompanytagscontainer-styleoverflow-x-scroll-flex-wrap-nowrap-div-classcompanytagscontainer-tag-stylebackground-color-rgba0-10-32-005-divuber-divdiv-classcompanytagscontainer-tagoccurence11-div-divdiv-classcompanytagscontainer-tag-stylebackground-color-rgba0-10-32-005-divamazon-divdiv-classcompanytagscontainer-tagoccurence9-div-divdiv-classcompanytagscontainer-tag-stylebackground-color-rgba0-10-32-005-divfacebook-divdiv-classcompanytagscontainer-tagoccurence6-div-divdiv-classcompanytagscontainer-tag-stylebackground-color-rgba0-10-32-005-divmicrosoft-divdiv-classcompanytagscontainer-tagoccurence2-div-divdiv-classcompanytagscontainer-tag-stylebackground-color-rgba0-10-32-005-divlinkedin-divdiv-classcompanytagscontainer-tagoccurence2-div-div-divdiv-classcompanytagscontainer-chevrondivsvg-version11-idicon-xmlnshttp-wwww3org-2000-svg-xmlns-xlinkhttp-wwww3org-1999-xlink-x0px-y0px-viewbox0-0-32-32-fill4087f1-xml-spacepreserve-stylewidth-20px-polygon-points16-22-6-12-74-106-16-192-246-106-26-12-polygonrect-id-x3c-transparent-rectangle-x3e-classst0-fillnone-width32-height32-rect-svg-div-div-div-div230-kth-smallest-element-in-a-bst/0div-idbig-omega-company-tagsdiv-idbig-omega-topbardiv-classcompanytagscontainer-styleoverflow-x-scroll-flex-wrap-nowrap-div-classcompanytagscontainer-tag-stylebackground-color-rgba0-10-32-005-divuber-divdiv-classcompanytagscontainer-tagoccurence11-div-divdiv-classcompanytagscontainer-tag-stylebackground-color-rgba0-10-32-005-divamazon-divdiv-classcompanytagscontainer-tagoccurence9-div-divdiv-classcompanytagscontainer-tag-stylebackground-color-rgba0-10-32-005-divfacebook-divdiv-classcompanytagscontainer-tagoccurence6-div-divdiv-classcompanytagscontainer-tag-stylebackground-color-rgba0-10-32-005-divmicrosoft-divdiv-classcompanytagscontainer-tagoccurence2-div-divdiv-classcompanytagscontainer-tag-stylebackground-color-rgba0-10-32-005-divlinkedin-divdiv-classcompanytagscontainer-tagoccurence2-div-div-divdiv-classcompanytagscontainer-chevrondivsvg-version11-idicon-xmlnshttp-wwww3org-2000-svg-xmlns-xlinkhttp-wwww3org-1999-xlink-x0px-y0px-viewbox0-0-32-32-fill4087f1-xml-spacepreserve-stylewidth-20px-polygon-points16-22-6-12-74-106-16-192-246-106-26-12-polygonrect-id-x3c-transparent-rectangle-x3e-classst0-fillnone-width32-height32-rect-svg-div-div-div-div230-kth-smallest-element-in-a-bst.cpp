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
    TreeNode* helper(TreeNode* root,int &k){
        if(!root)return root;
        TreeNode* lhs=helper(root->left,k);
        if(lhs)return lhs;
        k--;
        if(k==0)return root;
        return helper(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans=helper(root,k);
        if(ans)return ans->val;
        return -1;
    }
};