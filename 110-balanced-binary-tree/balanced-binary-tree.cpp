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
    bool isbalanced = true;
    int height(TreeNode * root){
        if(!root) return 0;

        int lH = height(root->left);
        int rH = height(root->right);

        // check for current Node is Balanced 
        if(isbalanced && abs(lH-rH) >1){
            isbalanced = false;
        }

        return max(lH,rH)+1;
     }

    
    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalanced;
    }
};