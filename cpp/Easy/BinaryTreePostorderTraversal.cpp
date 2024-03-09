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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> slt;
        if(root == nullptr)
            return slt;
        postorder(slt, root);
        return slt;
    } 

    void postorder(vector<int>& slt, TreeNode* root){
        if(root->left != nullptr)
            postorder(slt, root->left);
        if(root->right != nullptr)
            postorder(slt, root->right);
        slt.push_back(root->val);
    }
};
