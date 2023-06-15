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
    private:
    int findPos(vector<int>inorder, int size, int element){
        for(int i = 0 ; i < size ; ++i){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }

    TreeNode * build(vector<int> & inorder ,vector<int> &postorder, int size , int &postIndex , int inorderStart ,int inorderEnd){
        if(postIndex < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        int element = postorder[postIndex];
        postIndex--;

        TreeNode * root = new TreeNode(element);
        int pos = findPos(inorder,size,element);

        // right value call
        root->right = build(inorder,postorder,size,postIndex,pos+1,inorderEnd);
        root->left = build(inorder,postorder,size,postIndex,inorderStart,pos-1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int postIndex = size-1 , inorderEnd=size-1;
        int inorderStart = 0;

        TreeNode * root = build(inorder,postorder,size,postIndex,inorderStart,inorderEnd);
        return root;
    }
};