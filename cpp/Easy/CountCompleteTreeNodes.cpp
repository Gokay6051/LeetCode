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
    int countNodes(TreeNode* root) {
        int count = 1;
        if(root == nullptr)
            return 0;

        preorder(root, count);
        return count;
    }

    void preorder(TreeNode* root, int& count){
        
        if(root->left != nullptr){
            ++count;
            preorder(root->left, count);
        }

        if(root->right != nullptr){
            ++count;
            preorder(root->right, count);
        }
    }
};
