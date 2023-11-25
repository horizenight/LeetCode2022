class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        if (preStart == preEnd) {
            return root;
        }

        int idx = postStart;
        while (postorder[idx] != preorder[preStart + 1]) {
            idx++;
        }

        int len = idx - postStart + 1;

        root->left = solve(preorder, postorder, preStart + 1, preStart + len, postStart, idx);
        root->right = solve(preorder, postorder, preStart + len + 1, preEnd, idx + 1, postEnd);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        if (n == 0) {
            return nullptr;
        }
        return solve(preorder, postorder, 0, n - 1, 0, n - 1);
    }
};
