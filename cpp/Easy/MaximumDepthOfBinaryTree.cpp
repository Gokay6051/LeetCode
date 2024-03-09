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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        return findDepth(root);
    }

    int findDepth(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        
        int leftDepth;
        int rightDepth;

        if(root->left != nullptr)
            leftDepth = 1 + findDepth(root->left);
        else 
            leftDepth = 0;
        if(root->right != nullptr)
            rightDepth = 1 + findDepth(root->right);
        else
            rightDepth = 0;

        return max(leftDepth, rightDepth);
    }
};
