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
     pair<int,TreeNode*>lca(TreeNode* root, int p, int q){
        if(!root)return {0,NULL};
        auto lhs=lca(root->left,p,q);
        auto rhs=lca(root->right,p,q);
        if(lhs.first==2)return lhs;
        if(rhs.first==2)return rhs;
        int cnt=(root->val==p||root->val==q);
        cnt+=lhs.first+rhs.first;
        if(cnt==2||cnt==1)return {cnt,root};
        if(lhs.first)return lhs;
        if(rhs.first)return rhs;
        return {0,NULL};
    }
    string toStart="",toDest="";
    void given(TreeNode* root,int start,int dest,string& ans){
        if(!root)return ;
        if(root->val==dest){
            toDest=ans;
        }
        if(root->val==start){
            toStart=ans;
        }
        ans.push_back('L');
       given(root->left,start,dest,ans);
       ans.pop_back();
        ans.push_back('R');
       given(root->right,start,dest,ans);
        ans.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
         pair<int,TreeNode*>ans=lca(root,startValue,destValue);
       int depth=0;string rhs="";
       given(ans.second,startValue,destValue,rhs);
       for(char& ch:toStart)
       ch='U';
       return toStart+toDest;
    }
};