// class Solution {
// public:
//     void inorder(TreeNode * root , vector<int>&ans){
//         if(!root) return ;
//         // LNR => inorder 
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right,ans);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int>ans;
//         inorder(root,ans);
//         for(auto it : ans){
//             cout<<it<<" ";
//         }
//         return ans[k-1];
//     }
// };

class Solution {
public:
    int kthSmallest(TreeNode* root, int&k) {
        
        // base case 
        if(root==NULL) return -1;
// inorder 
        // left
        int leftAns = kthSmallest(root->left,k);
        if(leftAns != -1){
            return leftAns;
        }        // node 
        k--;
        if(k==0){
            return root->val;
        }
        int rightAns = kthSmallest(root->right,k);
        return rightAns;
        
    }
};