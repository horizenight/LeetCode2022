#include <algorithm>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // If k is greater than the size of the array, take its modulo
        k = k % n;
        
        // Rotate the entire array to the right
        std::reverse(nums.begin(), nums.end());
        
        // Rotate the first k elements to the right
        std::reverse(nums.begin(), nums.begin() + k);
        
        // Rotate the remaining elements to the right
        std::reverse(nums.begin() + k, nums.end());
    }
};
