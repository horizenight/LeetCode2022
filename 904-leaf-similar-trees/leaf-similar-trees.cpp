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
    vector<int>l1;
    void storeLeaf1(TreeNode * root){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL) l1.push_back(root->val);
        if(root->left != NULL) storeLeaf1(root->left); 
        if(root->right != NULL) storeLeaf1(root->right); 
    }
    vector<int>l2;
    void storeLeaf2(TreeNode * root){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL) l2.push_back(root->val);
        if(root->left != NULL) storeLeaf2(root->left); 
        if(root->right != NULL) storeLeaf2(root->right); 
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // store leaf node and compare 
        storeLeaf1(root1);
        storeLeaf2(root2);

        int flag = true;
        if(l1.size() != l2.size()) return false;
        for(int i = 0 ; i < l1.size();i++){
            if(l1[i] != l2[i]){
                flag = false;
                break;
            }
        }

        return flag;
    }
};