class Solution {
    
//     used stl approach a better way
     void solve(vector<int>& nums , int index ,vector<vector<int>>&fans){
        if(index >= nums.size()){
            fans.push_back(nums);
            return;
        }
    
        for(int j = index ; j < nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,index+1,fans);
        swap(nums[index],nums[j]);
    }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        
          vector<vector<int>>fans;
          
        int index = 0;
        
        solve(nums,index,fans);
        
        sort(fans.begin(),fans.end());
//         remove duplicates from ans 
//         ans vector 
        fans.erase( unique( fans.begin(), fans.end() ), fans.end() );
        
        
        return fans;

    }
};