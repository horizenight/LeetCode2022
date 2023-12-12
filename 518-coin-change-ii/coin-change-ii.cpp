class Solution {
public:
    int solveR(vector<int>& coins ,int i , int j){
        if(i == 0) return 0; // if no coins we cannot reach j
        if(j == 0 ) return 1; // we have reached our goals

        int exclude = solveR(coins,i-1,j);
        int include = 0;
        if(j - coins[i-1]>=0){
            // still a chance to reach the 0 
            include = solveR(coins, i, j - coins[i - 1]);
        }
        return exclude + include;
    }
    int solveMem( vector<vector<int>>&dp ,vector<int>& coins ,int i , int j ){
        if(i == 0) return dp[i][j] =  0; // if no coins we cannot reach j
        if(j == 0 ) return dp[i][j] = 1; // we have reached our goals

        if(dp[i][j] != -1) return dp[i][j];

        int exclude = solveMem(dp,coins,i-1,j);
        int include = 0;
        if(j - coins[i-1]>=0){
            // still a chance to reach the 0 
            include = solveMem(dp,coins, i, j - coins[i - 1]);
        }
        return  dp[i][j] =exclude + include;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solveMem(dp,coins,n,amount); // combination to achieve amount by n coins
    }
};