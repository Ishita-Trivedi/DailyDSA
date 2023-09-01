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
    bool isCousins(TreeNode* root, int x, int y) {
        int p1,p2,l1,l2;
        queue<TreeNode*>q;
        q.push(root);
        int level=-1;
        while(!q.empty()){
            int s=q.size();level++;
            while(s--){
            TreeNode* n=q.front();q.pop();
            if(n->left){
                q.push(n->left);
                if(n->left->val==x)
                {p1=n->val;l1=level;}
                else if(n->left->val==y)
                {p2=n->val;l2=level;}
            }
            if(n->right){
                q.push(n->right);
                if(n->right->val==x)
                {p1=n->val;l1=level;}
                else if(n->right->val==y)
                {p2=n->val;l2=level;}
            }
            }
        }
        return (l1==l2)&&(p1!=p2);
    }
};