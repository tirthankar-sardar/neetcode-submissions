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

class Codec {
   public:
    void preorder(TreeNode* root, string& s) {
        if (!root) {
            s += "# ";
            return;
        }

        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* build(stringstream& ss) {
        string x;
        ss >> x;

        if (x == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(x));
        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};
