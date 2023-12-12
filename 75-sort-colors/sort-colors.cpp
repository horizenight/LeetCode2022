class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p_0 = 0;
        int p_2 = nums.size() - 1;

        for (int i = 0; i <= p_2; ) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p_0]);
                p_0++;
                i++;  
            } else if (nums[i] == 2) {
                swap(nums[i], nums[p_2]);
                p_2--;
            } else {
                i++;
            }
        }
    }
};
