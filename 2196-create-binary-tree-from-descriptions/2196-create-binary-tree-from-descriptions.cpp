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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*>mp;
        set<int>parents,childs;
        for(auto vec:descriptions){
            TreeNode* p,*child;
            if(mp.find(vec[0])!=mp.end())
            p=mp[vec[0]];
            else{
                p=new TreeNode(vec[0]);
                mp[vec[0]]=p;
            }
            if(mp.find(vec[1])!=mp.end())
            child=mp[vec[1]];
            else{
                 child=new TreeNode(vec[1]);
                mp[vec[1]]=child;
            }
            if(vec[2])
            p->left=child;
            else
            p->right=child;
            parents.insert(vec[0]);
            childs.insert(vec[1]);
        }
        for(const int& p:parents){
            if(childs.find(p)==childs.end())
            return mp[p];
        }
        return NULL;
    }
};