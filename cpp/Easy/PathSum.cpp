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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        return findPath(root, targetSum, 0);
    }

    bool findPath(TreeNode* root, int targetSum, int sum){
        bool right, left;
        sum += root->val;
        if(sum == targetSum){
            if(!(root->left == nullptr && root->right == nullptr));
            else
                return true;
        }

        if(root->left == nullptr && root->right == nullptr)
            return false;
        
        if(root->left != nullptr)
            left = findPath(root->left, targetSum, sum);
        if(left == true)
            return true;
        
        if(root->right != nullptr)
            right = findPath(root->right, targetSum, sum);
        if(right == true)
            return true;
        
        return false;
    }
};
