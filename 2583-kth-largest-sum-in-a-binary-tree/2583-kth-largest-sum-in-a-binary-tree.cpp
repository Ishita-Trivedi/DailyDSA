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
    typedef long long ll;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)return -1;
        queue<TreeNode*>q;
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            ll sum=0;
            while(s){
                auto n=q.front();q.pop();
                sum+=n->val;
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
                s--;
            }
            // cout<<sum<<endl;
            pq.push(sum);
            if(pq.size()>k)
            pq.pop();
        }
        return pq.size()==k?pq.top():-1;
    }
};