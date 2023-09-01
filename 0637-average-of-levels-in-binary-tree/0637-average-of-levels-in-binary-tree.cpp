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
    vector<double> averageOfLevels(TreeNode* root) {
       vector<double>ans;
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
           double sum=0;
           int s=q.size();
           for(int i=1;i<=s;i++){
               TreeNode* n=q.front();q.pop();
                sum+=n->val;
                if(n->left)
                q.push(n->left);
                if(n->right)
                q.push(n->right);
           }
           sum/=s;
           ans.push_back(sum);
       }
       return ans;
    }
};