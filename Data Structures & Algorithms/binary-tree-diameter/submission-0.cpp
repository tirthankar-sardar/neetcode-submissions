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
int global = INT_MIN;
    int findMax(TreeNode* root){
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL){
            return 1;
        }
        int x = findMax(root -> left);
        int y = findMax(root -> right);
        int c = x + y;
        if(c > global){
            global = c;
        }
        return 1 + max(x,y);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL){
            return 0;
        }
        findMax(root);
        return global;
    }
};
