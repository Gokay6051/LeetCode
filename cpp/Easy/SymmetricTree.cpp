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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        //is left or right pointer null
        if(root->right == nullptr && root->left == nullptr)
            return true;
        if((root->right != nullptr && root->left == nullptr) || (root->right == nullptr && root->left != nullptr)){
            return false;
        }
        if(root->right->val != root->left->val)
            return false;
        
        bool slt = true;
        preorder(slt, root->right, root->left);
        return slt;
    }

    void preorder(bool& slt, TreeNode* right, TreeNode* left){
        //is pointer null
        if(right == nullptr && left == nullptr)
            return;
        else if((right != nullptr && left == nullptr) || (right == nullptr && left != nullptr)){
            slt = false;
            return;
        }
        
        //is pointer's right->right and left->left nodes null
        if(right->right == nullptr && left->left == nullptr);
        else if((right->right != nullptr && left->left == nullptr) || (right->right == nullptr && left->left != nullptr)){
            slt = false;
            return;
        }
        else if(right->right->val != left->left->val){
            slt = false;
            return;
        }

        //is pointer's right->left and left->right nodes null
        if(right->left == nullptr && left->right == nullptr);
        else if((right->left != nullptr && left->right == nullptr) || (right->left == nullptr && left->right != nullptr)){
            slt = false;
            return;
        }
        else if(right->left->val != left->right->val){
            slt = false;
            return;
        }


        preorder(slt, right->right, left->left);
        preorder(slt, right->left, left->right);
    }
};
