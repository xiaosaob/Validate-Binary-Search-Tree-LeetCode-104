// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return helper(root, NULL, NULL);
    }
    
    bool helper(TreeNode *root, TreeNode *left, TreeNode *right) {
        if(!root) return true;
        if(left && left->val >= root->val) return false;
        if(right && right->val <= root->val) return false;
        return helper(root->left, left, root) && helper(root->right, root, right);
    }
};
