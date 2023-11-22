class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,int>> que;
        que.push({0,0});
        vector<int> result ; 
        while(!que.empty()){
            auto [row,col] = que.front();
            que.pop();

            result.push_back(nums[row][col]);
            if(col == 0 && row +1 < nums.size())
                 que.push({row+1,col}); 
            if(col+1 < nums[row].size())  
                que.push({row,col+1});  

        }

        return result;
    }
};


// Using Map Approach 
 
// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//         // Diagonal Traversal => Think about Map always 
//         // Diagonal Element Row + col value is constant 

//         // Map [Row+col] = Values<int> 
//         unordered_map<int,vector<int>> mp;

//         for(int row = nums.size()-1 ;row>=0 ; row-- ){
//             for(int col = 0 ; col<nums[row].size() ; col++ ){
//                 int diagonal = row+col; 
//                 mp[diagonal].push_back(nums[row][col]);
//             }
//         }

//         vector<int>result;
//         int diagonal = 0 ;
//         while(mp.find(diagonal) != mp.end() ){
//             for(int &num : mp[diagonal]){
//                 result.push_back(num);
//             }
//             diagonal++;
//         }
//         return result;
//     }
// };