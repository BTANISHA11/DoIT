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
    
        void postorderTraversalHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return;
            
        // Step 3: Recursively traverse the right subtree
        postorderTraversalHelper(node->left, result);
        postorderTraversalHelper(node->right, result);
        
 // Step 2: Recursively traverse the left subtree
        
        result.push_back(node->val);
        // Step 1: Visit the root node
        
       
    }

    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> result;
        postorderTraversalHelper(root, result);
        return result;
   
    }
};