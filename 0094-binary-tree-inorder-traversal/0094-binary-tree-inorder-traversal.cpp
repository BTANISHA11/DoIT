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
void inorderTraversalHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return;
 // Step 2: Recursively traverse the left subtree
        inorderTraversalHelper(node->left, result);
        // Step 1: Visit the root node
        result.push_back(node->val);
       
        // Step 3: Recursively traverse the right subtree
        inorderTraversalHelper(node->right, result);
    }

     vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result;
        inorderTraversalHelper(root, result);
        return result;
   
    }
};