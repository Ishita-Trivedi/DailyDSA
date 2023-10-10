/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto n=q.front();q.pop();
            if(n)
            ans+=to_string(n->val)+",";
            else
           { ans+="#,";continue;}
            if(n->left)q.push(n->left);
            else
            q.push(NULL);
            if(n->right)q.push(n->right);
            else
            q.push(NULL);
        }
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()||data[0]=='#')
        return NULL;
        stringstream s(data);string st;
        getline(s,st,',');
        TreeNode* root=new TreeNode(stoi(st));
        queue<TreeNode*>q;q.push(root);
        while(!q.empty()){
            auto n=q.front();q.pop();
            bool lhs=true;
            for(int i=1;i<=2;i++){
                getline(s,st,',');
                TreeNode* newn;
                if(st=="#")newn=NULL;
                else
                newn=new TreeNode(stoi(st));
                if(lhs)
                n->left=newn;
                else
                n->right=newn;
                lhs=!lhs;
                if(newn)q.push(newn);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));