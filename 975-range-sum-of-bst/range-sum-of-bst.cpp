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
    int ans = 0;
    void solve(TreeNode * root , int low , int high){
        if(root == NULL) return ;
        // cout<<root->val<<" ";
        if(root ->left != NULL) solve(root->left,low,high);
        if(root ->right != NULL) solve(root->right,low,high);
        if(root->val >= low && root->val <=high){
            cout<<root->val<<" ";
            ans+= root->val;
        }
       

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
       // do a traversal and add the value too the answer value
       solve(root,low,high);
       return ans; 
    }
};