/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postordr(Node* root,vector<int>&order){
        if(!root)return;
        for(auto v:root->children){
            postordr(v,order);
        }
        order.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        postordr(root,ans);
        return ans;
    }
};