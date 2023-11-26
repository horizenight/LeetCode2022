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
    bool identical = false;
    bool isIdentical(TreeNode * p , TreeNode * q){
        
        if(p == NULL && q == NULL) return true;
        if(p== NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        return isIdentical(p->left,q->left) && isIdentical(p->right,q->right);}

    void solve(TreeNode * root , TreeNode * subRoot){
        if(root == NULL) return;
        // exploring left node 
        if(root->left){
            solve(root->left,subRoot);
        }
        // Node 
        if(root->val == subRoot->val){
            // can be identical 
            cout<<root->val <<" "<<subRoot->val;
            bool flag = isIdentical(root,subRoot);
            if(flag){
                identical = flag;
            }
        }
         if(root->right){
            solve(root->right,subRoot);
        }

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // find the subRroot in main tree  / /can be more than one 
        // better approach : go through inonder traversal and find all nodes and the call on the Identical if its true then make indetical true
        // using inorder traversal : LNR

        solve(root,subRoot);

        return identical ;
    }
};