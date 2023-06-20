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
int posi(vector<int> & inorder,int target){

    for(int i = 0 ; i<inorder.size() ;i++){
        if(target == inorder[i]){
            return i;
        }
    }

    return -1;
}

TreeNode * buildTreeIn(vector<int>&preorder , vector<int>& inorder , int &preIndex , int inorderStart, int inorderEnd){
    if(preIndex >= inorder.size() || inorderStart > inorderEnd ){
        return NULL;
    }
    int element = preorder[preIndex++];
    TreeNode * root = new TreeNode(element);

    // call to left tree and right tree
    int pos = posi(inorder,element);

    // left and right tree
    root->left = buildTreeIn(preorder,inorder,preIndex,inorderStart,pos-1);

    root->right = buildTreeIn(preorder,inorder,preIndex,pos+1,inorderEnd);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // inorder => LNR
        // preorder => NLR
        int preIndex = 0;
        TreeNode * root = buildTreeIn(preorder,inorder,preIndex,0,inorder.size()-1);
        // steps would be to => 
        // the start index would be the Root Node  => so first find the root index 
        // call the pos for the inorder traversal 

        // base case
        return root;

    }
};