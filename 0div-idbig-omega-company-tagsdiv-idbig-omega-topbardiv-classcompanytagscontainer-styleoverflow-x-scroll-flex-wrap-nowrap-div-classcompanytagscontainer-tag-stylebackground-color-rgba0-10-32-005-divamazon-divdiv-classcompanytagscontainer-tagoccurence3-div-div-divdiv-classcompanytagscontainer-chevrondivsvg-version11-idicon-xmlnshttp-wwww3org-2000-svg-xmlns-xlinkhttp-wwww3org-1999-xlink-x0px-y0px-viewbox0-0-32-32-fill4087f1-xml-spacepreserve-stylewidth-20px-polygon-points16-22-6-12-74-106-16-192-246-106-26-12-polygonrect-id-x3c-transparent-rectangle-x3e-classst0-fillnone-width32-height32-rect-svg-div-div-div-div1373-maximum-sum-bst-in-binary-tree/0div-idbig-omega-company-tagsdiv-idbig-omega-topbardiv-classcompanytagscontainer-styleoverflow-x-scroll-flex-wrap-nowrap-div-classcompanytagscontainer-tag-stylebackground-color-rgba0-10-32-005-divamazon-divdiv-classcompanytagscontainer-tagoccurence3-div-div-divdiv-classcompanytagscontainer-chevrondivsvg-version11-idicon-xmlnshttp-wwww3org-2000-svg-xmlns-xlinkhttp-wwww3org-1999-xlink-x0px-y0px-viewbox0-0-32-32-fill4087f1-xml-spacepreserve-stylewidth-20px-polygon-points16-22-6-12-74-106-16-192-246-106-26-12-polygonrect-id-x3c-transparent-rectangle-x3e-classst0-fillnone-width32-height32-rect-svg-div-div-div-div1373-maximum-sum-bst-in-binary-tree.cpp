/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class storeinfo {
public:
    int maxi, mini, sum;
    bool isbst;
    // Default constructor
    storeinfo() : maxi(INT_MIN), mini(INT_MAX), sum(0), isbst(true) {}

    // Parameterized constructor
    storeinfo(int maxi, int mini, int sum, bool isbst)
        : maxi(maxi), mini(mini), sum(sum), isbst(isbst) {}
};
class Solution {
private:
    storeinfo helper(TreeNode* root, int& ans) {
        if (!root)
            return storeinfo(INT_MIN, INT_MAX, 0, 1);
        storeinfo lhs = helper(root->left, ans);
        storeinfo rhs = helper(root->right, ans);
        // calculate for current node
        storeinfo curr;
        curr.sum = root->val + lhs.sum + rhs.sum;

        curr.maxi = max(root->val, rhs.maxi); // as greater values on rhs
        curr.mini = min(root->val,lhs.mini); // as smaller values on lhs
        // now condition for being the current node is a bst
        // 1.left and right subtree are also bst
        // 2.roots val lies btw maximum of left subtree ans minimum of right subtree
        if (lhs.isbst && rhs.isbst &&
            (root->val > lhs.maxi && root->val < rhs.mini)) {
            curr.isbst = true;
            ans = max(ans, curr.sum);
        } else
            curr.isbst = false;
        return curr;
    }

public:
    int maxSumBST(TreeNode* root) {
        int maxi = 0; // as negatives not allowed
        helper(root, maxi);
        return maxi;
    }
};