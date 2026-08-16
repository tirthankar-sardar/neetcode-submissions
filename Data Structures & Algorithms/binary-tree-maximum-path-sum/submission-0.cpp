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
        if(!root) return 0;
        if(root -> left == NULL && root -> right == NULL){
            if(root -> val > global){
                global = root -> val;
            }
        }
        int x = findMax(root -> left);
        int y = findMax(root -> right);
        int sum = (root -> val) + x + y;

        if(sum > global){
            global = sum;
        }

        if(root->val > global) global = root -> val;
        if(root->val + x > global) global = root -> val + x;
        if(root -> val + y > global) global = root -> val + y;

        return root -> val > root -> val + max(x,y) ? root -> val : root -> val + max(x,y);
    }
    int maxPathSum(TreeNode* root) {
        findMax(root);
        return global;
    }
};
