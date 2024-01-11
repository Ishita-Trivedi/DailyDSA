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
 class node{
     public:
     int maxi,mini;
     node(int a,int b){
         this->maxi=a;
         this->mini=b;
     }
 };
class Solution {
private:
    node helper(TreeNode* root,int& ans){
        if(!root)return {INT_MIN,INT_MAX};
        if(!root->left&&!root->right)return {root->val,root->val};
        node l=helper(root->left,ans);
        node r=helper(root->right,ans);
        int maxi,mini;
        maxi=max({l.maxi,r.maxi});mini=min({l.mini,r.mini});
        if(maxi!=INT_MIN)//not a null node
        ans=max(ans,abs(root->val-maxi));
        if(mini!=INT_MAX)
        ans=max(ans,abs(root->val-mini));
        return {max(maxi,root->val),min(mini,root->val)};             
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
    }
};