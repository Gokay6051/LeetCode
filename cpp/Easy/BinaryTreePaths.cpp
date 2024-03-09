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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> slt;

        solution(slt, "", root);

        return slt;
    }

    void solution(vector<string>& slt, string current, TreeNode* root){
        current += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr){
            slt.push_back(current);
            return;
        }

        if(root->left != nullptr){
            solution(slt, current + "->", root->left);
        }

        if(root->right != nullptr) {
            solution(slt, current + "->", root->right);
        }
    }
};
