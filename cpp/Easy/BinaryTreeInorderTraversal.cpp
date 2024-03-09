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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> slt;

        if(root == nullptr)
            return slt;
            
        inorder(slt, root);
        return slt; 
    }

    void inorder(vector<int>& slt, TreeNode* root){
        if(root->left != nullptr)
            inorder(slt, root->left);
        
        slt.push_back(root->val);

        if(root->right != nullptr)
            inorder(slt, root->right);
    }
};
