class Solution {
public:
    TreeNode* prev = nullptr;
    
    void flatten(TreeNode* root) {
        if (!root) return;
        
        // Store the right child
        TreeNode* right = root->right;
        
        // If there's a previous node, make it the right child of the current node
        if (prev) {
            prev->left = nullptr;
            prev->right = root;
        }
        
        // Update prev to the current node
        prev = root;
        
        // Recur for the left and right subtrees
        flatten(root->left);
        flatten(right);
    }
};
