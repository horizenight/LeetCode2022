class Solution {
public:
    int solveR(vector<int>& arr , int curr , int prev){
        if(curr >=arr.size()) return 0;
        int include = 0 ;
        if( (  prev == -1 )   || arr[curr] >arr[prev] ){
            include = 1 + solveR(arr,curr+1,curr);
        }
        int exclude = solveR(arr,curr+1, prev);

        return max(include , exclude );
    }
      int solveBU(vector<int> &nums)
    {
        vector<vector <int>> dp(nums.size() + 1, vector<int> (nums.size() + 1, 0));

            for (int curr = nums.size() - 1; curr >= 0; curr--)
            {
                for (int prev = curr - 1; prev >= -1; prev--)
                {
                    int include = 0;
                    if (prev == -1 || nums[curr] > nums[prev])
                    {
                        include = 1+ dp[curr + 1][curr+1];
                    }
                    int exclude = 0 + dp[curr + 1][prev+1];
                    int ans = max(include, exclude);

                    dp[curr][prev+1] = ans;
                }
            }

            return dp[0][0];
        }
    int lengthOfLIS(vector<int>& nums) {
        // include or excludde 
       int ans = solveBU(nums);
            return ans;
    }
};