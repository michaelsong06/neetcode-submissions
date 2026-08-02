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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (preorder.empty() || inorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);

        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int rootIndexIn = distance(inorder.begin(), it);
        vector<int> leftIn(inorder.begin(), inorder.begin() + rootIndexIn);
        vector<int> rightIn(inorder.begin() + rootIndexIn + 1, inorder.end());

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + leftIn.size() + 1);
        vector<int> rightPre(preorder.begin() + leftIn.size() + 1, preorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};
