/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
typedef pair<ListNode*,TreeNode*>p;
public:
    bool ans=false;
    bool check(ListNode* linked,TreeNode* r){
       queue<p>q;
       q.push({linked,r});
       while(!q.empty()){
        auto t=q.front();q.pop();
        ListNode* l=t.first;
        TreeNode* rt=t.second;
        if(l->val==rt->val){
            l=l->next;
            if(!l)return true;
            if(rt->left&&l->val==rt->left->val)
            q.push({l,rt->left});
            if(rt->right&&l->val==rt->right->val)
            q.push({l,rt->right});
        }
       }
       return false;
    }
    void inorder(TreeNode* root,ListNode* head){
        if(!root||ans)return;
        if(root->val==head->val)
        ans=check(head,root);
        inorder(root->left,head);
        inorder(root->right,head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)return true;
        inorder(root,head);
        return ans;
    }
};