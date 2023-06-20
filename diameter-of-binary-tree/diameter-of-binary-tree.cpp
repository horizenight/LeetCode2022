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
    int D =0;
    private:
    
    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lHeight = maxDepth(root->left);
        int rHeight = maxDepth(root->right);
        int currD = lHeight + rHeight;
        D = max(D,currD);
        int ans = max(lHeight,rHeight) +1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        maxDepth(root);
        return D;

        
    }
};