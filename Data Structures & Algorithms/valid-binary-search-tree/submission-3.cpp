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
    bool isValidBST(TreeNode* root) {
        
        return dfsCheck(root, INT_MIN, INT_MAX);
    }

    bool dfsCheck(TreeNode* root, int LB, int UB) {
        
        if (!root) return true;

        if (root->val <= LB || root->val >= UB) return false;

        return dfsCheck(root->left, LB, min(UB, root->val)) && dfsCheck(root->right, max(LB, root->val), UB);
    }

};
