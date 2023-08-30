
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(),nxt = 1e9+7;
        for(int j = n-1 ; j>= 0 ;j--){
            if(nums[j] <= nxt){
                nxt = nums[j];
                continue;
            }

            long long parts = ceil(nums[j] / (double) nxt);
            ans += parts-1;
            nxt = nums[j] / parts;

           
        }
         return ans;
    }
};