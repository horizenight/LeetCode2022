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
    bool check(TreeNode * left , TreeNode * right){
        if(left == NULL || right == NULL) return left == right;
        if(left -> val != right ->val) return false;

        return check(left->left , right ->right) && check(left->right , right ->left);
    }

    bool isMirror(TreeNode * p , TreeNode * q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL ) return false;
    if(p->val!= q-> val) return false;

    return isMirror(p->left , q->right) && isMirror(p->right,q->left);
}
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isMirror(root->left,root->right);
    }
};