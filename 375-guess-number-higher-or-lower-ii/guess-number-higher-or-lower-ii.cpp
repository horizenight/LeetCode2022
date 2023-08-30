class Solution {
public:
    int solveUsingRecursion(int start , int end){
        if(start >=end){
            return 0;
        }
        int maxi = INT_MAX;
        for(int i = start ; i<=end ;i++){
            maxi = min(maxi,i+max(solveUsingRecursion(start,i-1) ,solveUsingRecursion(i+1 ,end)));
        }
        return maxi;
    }
    int solveUsingMem(int start , int end,vector<vector<int>>& dp){
        if(start >=end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int maxi = INT_MAX;
        for(int i = start ; i<=end ;i++){
            maxi = min(maxi,i+max(solveUsingMem(start,i-1,dp) ,solveUsingMem(i+1 ,end,dp)));
        }
        return dp[start][end] =  maxi;
    }

    int solveUsingTab(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2,0));
        
        //base case handled as intiallised with zero 

        for(int start = n; start>=1 ; start--){
            // end going from end  to zero 
            for(int end = 1 ; end <=n ; end++ ){
                if(start >= end){
                    continue;
                }
                else{
                    int maxi = INT_MAX;
                     for(int i = start ; i<=end ;i++){
                        maxi = min(maxi,i+max(dp[start][i-1] , dp[i+1][end]));
                    }
                    dp[start][end] = maxi;
                }
              
            }
        }

        return dp[1][n];
        
    }
  
    int getMoneyAmount(int n) {
        
        // first logic that I can think 
        // first get the min value for 1 to n 
        // get the max value for 1 to n 

        // int ans = solveUsingRecursion(1,n);
        // vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));
        int ans = solveUsingTab(n);
        return ans;

    }
};