class Solution {
public:
    int solveUsingRecursion(int n){
        if(n == 0 || n == 1 ){
            return 1;
        }
       
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);

        return ans;
    }
    int solveUsingMem(int n , vector<int> &dp){
           if(n == 0 || n == 1 ){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
       
        int ans = solveUsingMem(n-1,dp) + solveUsingMem(n-2,dp);

        return dp[n] = ans;
    }

    int climbStairs(int n) {
        // insitalising dp array 
        vector<int> dp(n+1,-1);
        int ans = solveUsingMem( n ,dp);
        return ans;
    }
};