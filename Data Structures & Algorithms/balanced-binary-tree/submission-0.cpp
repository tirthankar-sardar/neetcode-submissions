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
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root -> left), height(root -> right));
    }
    int solve(TreeNode* root){
        int left = 1 + height(root -> left);
        int right = 1 + height(root -> right);
        if(abs(left - right) > 1)
            return 0;
        return 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(solve(root)){
            if(isBalanced(root -> left) && isBalanced(root -> right)){
                return true;
            }return false;
        }
        return false;
    }
};
