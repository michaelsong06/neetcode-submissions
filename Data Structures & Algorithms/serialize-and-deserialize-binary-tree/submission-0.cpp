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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string output = "";

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node) {
                output.append(to_string(node->val));
                s.push(node->right);
                s.push(node->left);
            } else {
                output.append("null");
            }
            output.push_back('|');
        }
        cout << output << "\n";
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> dataArray;
        string workingData = "";
        for (char c : data) {
            if (c != '|') workingData.push_back(c);
            else {
                dataArray.push_back(workingData);
                workingData = "";
            }
        }

        int index = -1;
        return buildTree(dataArray, index);
    }

    TreeNode* buildTree(vector<string>& dataArray, int& index) {
        
        index++;
        if (index >= dataArray.size()) return nullptr;
        if ((dataArray[index]) == "null") return nullptr;
        int val = stoi(dataArray[index]);
        
        TreeNode* node = new TreeNode(val);
        node->left = buildTree(dataArray, index);
        node->right = buildTree(dataArray, index);
        
        return node;
    }
};
