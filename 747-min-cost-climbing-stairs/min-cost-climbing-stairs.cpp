class Solution {
public:
    int soR(vector<int>& cost, int n){
        if(n == 0 || n == 1) {
            return 0;
        }

        int ans = min(cost[n-1] + soR(cost,n-1) , cost[n-2]+ soR(cost,n-2));


        return ans;


    }
    int soM(vector<int> & cost , int n , vector<int>&dp){
         if(n == 0 || n == 1) {
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = min(cost[n-1] + soM(cost,n-1,dp) , cost[n-2]+ soM(cost,n-2,dp));

        return dp[n] = ans;

    }

    int soT(vector<int> & cost , int n){
        vector<int>dp(n+1,0);
        //base case already handled
        for(int i = 2 ; i <= n ;i++){
            dp[i] = min(cost[i-1] + dp[i-1] , cost[i-2] + dp[i-2]);
        }
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int>dp(n+1,-1);
        int ans = soT(cost ,n);
        return ans;
    }
};