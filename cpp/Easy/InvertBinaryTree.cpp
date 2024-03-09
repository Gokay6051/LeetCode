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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* newRoot = new TreeNode;
        
        if(root == nullptr)
            return root;

        newRoot->val = root->val;
        invert(newRoot, root);

        return newRoot;
    }

    void invert(TreeNode* newRoot, TreeNode* root){
        if(root->left == nullptr && root->right == nullptr)
            return;
        
        if(root->left != nullptr){
            newRoot->right = new TreeNode;
            newRoot->right->val = root->left->val;
            invert(newRoot->right, root->left);
        }

        if(root->right != nullptr){
            newRoot->left = new TreeNode;
            newRoot->left->val = root->right->val;
            invert(newRoot->left, root->right);
        }
    }
};
