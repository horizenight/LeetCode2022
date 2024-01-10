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
    TreeNode * makeMap(TreeNode * root , unordered_map<TreeNode * , TreeNode*> &parentMap,int start){
        TreeNode * infected = 0;
        queue<TreeNode*> q;
        q.push(root);
        parentMap[root] = 0;

        while(!q.empty()){
            TreeNode * frontNode = q.front();q.pop();
            if(frontNode->val == start){
                infected = frontNode;
            }
            if(frontNode -> left){
                q.push(frontNode->left);
                parentMap[frontNode->left] = frontNode;
            }
            if(frontNode -> right){
                q.push(frontNode->right);
                parentMap[frontNode->right] = frontNode;
            }
        }

        return infected;
    }

    int infectedTree(TreeNode* infectedNode,unordered_map<TreeNode * , TreeNode * > parentMap ){
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        int count = 0;
        q.push(infectedNode);
        visited[infectedNode] = true;

        while(!q.empty()){
            int level = q.size();
            bool isInfectedSpread = 0;

            for(int i = 0 ; i < level ; i++){
                TreeNode * frontNode = q.front();q.pop();
                if(frontNode->left != NULL && visited[frontNode->left] == false){
                    q.push(frontNode->left);
                     visited[frontNode->left] = true;
                     isInfectedSpread =1;
                }
                if(frontNode->right != NULL && visited[frontNode->right] == false){
                    q.push(frontNode->right);
                     visited[frontNode->right] = true;
                     isInfectedSpread = 1;
                }
                if(parentMap[frontNode] && visited[parentMap[frontNode]] == false){
                    q.push(parentMap[frontNode]);
                    visited[parentMap[frontNode]] = true;
                    isInfectedSpread =1;
                }
            }
            if(isInfectedSpread){
                count++;
            }
        }
        return count;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode * , TreeNode * > parentMap;
        TreeNode * targetNode = makeMap(root,parentMap,start);
        return infectedTree(targetNode,parentMap);
    }
};