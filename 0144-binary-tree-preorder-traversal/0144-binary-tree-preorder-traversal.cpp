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
    void preorderTraversalHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return;

        // Step 1: Visit the root node
        result.push_back(node->val);
        // Step 2: Recursively traverse the left subtree
        preorderTraversalHelper(node->left, result);
        // Step 3: Recursively traverse the right subtree
        preorderTraversalHelper(node->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversalHelper(root, result);
        return result;
    }
};