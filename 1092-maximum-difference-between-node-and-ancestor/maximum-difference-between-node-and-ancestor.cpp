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
    pair<int,int> solve(TreeNode * root){
        int mini = root->val;
        int maxi = root->val;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* frontNode = q.front();q.pop();
            mini = min(mini , frontNode->val);
            maxi = max(maxi,frontNode->val);
            if(frontNode->left != NULL) q.push(frontNode->left);
            if(frontNode->right != NULL) q.push(frontNode->right);
        }
        return {mini,maxi};
    }
    int maxAncestorDiff(TreeNode* root) {
        int gmaxDiff = 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode * frontNode = q.front();q.pop();
            pair<int,int> values = solve(frontNode);
            // cout<<values.first <<" "<<values.second<<" ";
            int minDiff = abs( frontNode->val - values.first );
            int maxDiff = abs( frontNode->val - values.second );
            cout<<minDiff<<" "<<maxDiff<<" ";
            gmaxDiff = max({minDiff,maxDiff,gmaxDiff});
            if(frontNode->left != NULL) q.push(frontNode->left);
            if(frontNode->right != NULL) q.push(frontNode->right);
        }

        return gmaxDiff;
    }
};