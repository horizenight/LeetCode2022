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
int height(TreeNode * root){
    if(root == NULL){
        return 0;
    }

    int ans = 1 + max(height(root->right),height(root->left));

    return ans; 
}
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }

        int leftHeight  = height(root->left);
        int rightHeight = height(root->right);

        int diff = abs(leftHeight - rightHeight);

        bool ans1 = (diff <=1);

        // erecursion
        bool leftAns = isBalanced(root->right);
        bool rightAns = isBalanced(root->left);

        if(ans1 && leftAns && rightAns){
            return true;
        }
        else{
            return false;
        }
    }
};