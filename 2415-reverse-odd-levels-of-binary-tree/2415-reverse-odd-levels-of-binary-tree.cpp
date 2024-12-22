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
    void swapThem(TreeNode* & a,TreeNode* &b){
        if(!a || !b)return;
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root||!root->left)return root;//single or null nodes returned
        queue<TreeNode*>q;
        q.push(root);
        bool even=true;
        while(!q.empty()){
            int s=q.size();
            vector<TreeNode*>nodes;
            while(s--){
                TreeNode* n=q.front();q.pop();
                if(even&&n)
                nodes.push_back(n);
                //perfect BT so lhs&& rhs present
                if(n->left)
                q.push(n->left);
                if(n->right)
                q.push(n->right);
            }
            if(even){
                if(nodes.size()==1){
                   swapThem(nodes[0]->left,nodes[0]->right);
                }
                else{
                    int ns=nodes.size();
                    for(int i=0;i<ns/2;i++){
                    swapThem(nodes[i]->left,nodes[ns-1-i]->right);
                    swapThem(nodes[i]->right,nodes[ns-1-i]->left);
                    }
                }
            }
            even=!even;
        }
        return root;
    }
};