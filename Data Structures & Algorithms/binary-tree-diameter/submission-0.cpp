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
private:
    int diameter = 0;
public:
    int heightOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int l = heightOfBinaryTree(root->left);
        int r = heightOfBinaryTree(root->right);

        diameter = max(diameter, l + r);

        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        heightOfBinaryTree(root);
        return diameter;
    }
};
