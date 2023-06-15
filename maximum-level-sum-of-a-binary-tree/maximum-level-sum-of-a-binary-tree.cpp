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
    int maxLevelSum(TreeNode* root) {
        // logic do Level order traversal but sum at the end
        int max_sum = INT_MIN;
        int sum = 0;
        queue<TreeNode*>q;


        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();
        
            if(temp == NULL){
                max_sum = max(sum,max_sum);
                sum = 0;
                if(!q.empty()){
                q.push(NULL);
            }
                
            }else{
            sum+= temp->val;
            if(temp -> left){
                q.push(temp-> left);
            }
            if(temp->right){
                q.push(temp-> right);
            }

            }

        }
        // now we have the max sum 
        // which level has that max_sum return that 

        int level = 0;
        sum =0;
        
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();
        
            if(temp == NULL){
                level++;
                if(sum == max_sum){
                    return level;
                }
                sum = 0;
                if(!q.empty()){
                q.push(NULL);
            }
                
            }else{
            sum+= temp->val;
            if(temp -> left){
                q.push(temp-> left);
            }
            if(temp->right){
                q.push(temp-> right);
            }

            }

        }


        return max_sum;
        // return 0;
        /*
        */
    }
};