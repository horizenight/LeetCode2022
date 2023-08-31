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

    int solveUsingTab(int n){
        vector<int> dp(n+1,0);
        // base case into dp 
        dp[0] = 1;
        dp[1] = 1;
        // now dp array will go opposite from Mem
        for(int i = 2 ; i <= n ;i++){
            dp[i] = dp[i-1] + dp[i-2];
            
        }
        return dp[n];
    }

    int climbStairs(int n) {
        // insitalising dp array 
        vector<int> dp(n+1,-1);
        int ans = solveUsingTab( n );
        return ans;
    }
};