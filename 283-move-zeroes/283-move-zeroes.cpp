class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
//         have to do mofied bubble sort 
        
        for(int last = 0 , cur = 0 ; cur< nums.size() ; cur++){
            if(nums[cur]!=0){
                swap(nums[last++],nums[cur]);
                
            }
        }
        
    }
};