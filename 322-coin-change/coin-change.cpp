class Solution {
public:
    int solveR(vector<int>&coins,int i,int j){

        if(i == 0) return INT_MAX-1 ; // we cannot reach j
        if(j == 0) return 0; // if we reach 0 that means we reached the goal 

        // if divisible then that will be the least amopunt 
        //Transaition State: 
        // cases 1 : include but not move , include but move , exclude 
        int exclude = solveR(coins,i-1,j); 
        int include = INT_MAX-1;
        if(j - coins[i-1] >=0){
            //we can include it only once or more than once 
            include = min(1+solveR(coins,i,j-coins[i-1]) , 1 + solveR(coins,i-1,j-coins[i-1]));
        }

        return min(exclude,include);    
    }

    int solveMem( vector<vector<int>> & dp , vector<int>&coins,int i,int j){
        if(i == 0) return dp[i][j] = INT_MAX-1 ; // we cannot reach j
        if(j == 0) return dp[i][j] =  0; // if we reach 0 that means we reached the goal 
        if(dp[i][j] !=  INT_MAX - 1) return dp[i][j];
        // if divisible then that will be the least amopunt 
        //Transaition State: 
        // cases 1 : include but not move , include but move , exclude 
        int exclude = solveMem(dp,coins,i-1,j); 
        int include = INT_MAX-1;
        if(j - coins[i-1] >=0){
            //we can include it only once or more than once 
            include = min(1+solveMem(dp,coins,i,j-coins[i-1]) , 1 + solveMem(dp,coins,i-1,j-coins[i-1]));
        }

        return dp[i][j] =  min(exclude,include);
    }

int solveT(vector<int>&coins , int amount){
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX - 1));

    // Base case
    for (int i = 0; i <= coins.size(); i++) {
        dp[i][0] = 0;
    }

   for (int i = 1; i <= coins.size(); i++) {
        for (int j = 0; j <= amount; j++) {
            int exclude = dp[i - 1][j];
            int include = INT_MAX - 1;

            if (j - coins[i - 1] >= 0) {
                include = min(1 + dp[i][j - coins[i - 1]], 1 + dp[i - 1][j - coins[i - 1]]);
            }

            dp[i][j] = min(exclude, include);
        }
    }
    return dp[coins.size()][amount];
    }
   

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX-1));
       int ans = solveT(coins,amount);

       if(ans == INT_MAX-1){
           return -1;
       }
       return ans;
    }
};