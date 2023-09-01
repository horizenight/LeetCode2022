class Solution {
public:

    int soR(vector<int>& nums, int n,int i){
        if(i >= n){
            return 0;
            //at the end of array
        }
        int include = nums[i] + soR(nums,n,i+2);
        int exclude = 0 + soR(nums,n,i+1);

        int ans = max(include,exclude);

        return ans;
    }

    int soRM(vector<int> & nums , int n , int i, vector<int> &dp){
        if(i >= n){
            return 0;
            //at the end of array
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int include = nums[i] + soRM(nums,n,i+2,dp);
        int exclude = 0 + soRM(nums,n,i+1,dp);

        int ans = max(include,exclude);

        return dp[i] = ans;

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int>dp(n+1,-1);
        int ans = soRM(nums,n,i,dp);
        return ans;
    }
};