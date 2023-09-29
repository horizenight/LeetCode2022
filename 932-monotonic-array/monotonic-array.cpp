class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        bool increase = false;
        bool decrease = false;

        for(int i = 0 ; i< nums.size() - 1 ;i++){
            if(nums[i] < nums[i+1]){
                increase = true;
            }
            if(nums[i] > nums[i+1]){
                decrease = true;
            }
        }

        if(increase && decrease){
            return false;
        }

        return true;
    }
};