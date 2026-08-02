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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> output;

        queue<TreeNode*> q;
        if (root) q.push(root);
        else return output;

        while (!q.empty()) {
            vector<int> layer;
            
            for (int i = q.size(); i > 0; i--) {
                TreeNode* current = q.front();
                q.pop();
                if (current) {
                    layer.push_back(current->val);
                    q.push(current->left);
                    q.push(current->right);
                }
            }
            if (!layer.empty()) {
                output.push_back(layer);
            }
        }

        return output;

    }
};
