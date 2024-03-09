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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> slt;
        if(root == nullptr)
            return slt;
        preorder(slt, root);
        return slt;
    }

    void preorder(vector<int>& slt, TreeNode* root) {
        slt.push_back(root->val);
        if(root->left != nullptr)
            preorder(slt, root->left);
        if(root->right != nullptr)
            preorder(slt, root->right);
    }
};
