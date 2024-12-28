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
    int Countswap(vector<int>&values,unordered_map<int,int>&mp){
        int count=0;
        vector<int>sorted=values;
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<values.size();i++){
            if(sorted[i]==values[i])continue;
            int swapidx=mp[sorted[i]];
            mp[sorted[i]]=i;
            mp[values[i]]=swapidx;
            swap(values[i],values[swapidx]);
            count++;
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int s=q.size();
            unordered_map<int,int>mp;
            vector<int>values;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();q.pop();
                values.push_back(node->val);
                mp[node->val]=i;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            cnt+=Countswap(values,mp);
        }
        return cnt;
    }
};