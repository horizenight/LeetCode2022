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

    string tree2str(TreeNode* root) {
        // preorder traversal : NLR
        if(root == NULL) return "";
        string result = to_string(root->val);
        std::string leftSubtree = tree2str(root->left);
        std::string rightSubtree = tree2str(root->right);
if (leftSubtree.empty() && rightSubtree.empty()) {
            // Both left and right subtrees are empty, return the current result
            return result;
        }
         if (leftSubtree.empty()) {
            // Left subtree is empty, include empty parentheses for it and the right subtree
            return result + "()" + "(" + rightSubtree + ")";
        }
        if (rightSubtree.empty()) {
            return result + "(" + leftSubtree + ")";
        }
        return result + "(" + leftSubtree + ")" + "(" + rightSubtree + ")";
    }
};