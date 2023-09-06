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
    int sums(TreeNode* root,int& maxi){
        if(!root)return 0;
        int left=sums(root->left,maxi);
        int right=sums(root->right,maxi);
        //continue previous path or start a new
        int path=max(max(left,right)+root->val,root->val);
        int check=max(path,root->val+left+right);//check round path
        maxi=max(check,maxi);
        return path;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int maxi=INT_MIN;
         sums(root,maxi);
         return maxi;
    }
};