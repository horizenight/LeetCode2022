class Solution {
public:
    int suR(int n){
        if(n <= 1){
            return n;
        }

        int ans = suR(n-1) + suR(n-2);
        return ans;
    }

    int suRM(int n , vector<int> &dp){
        if(n <= 1){
                    return n;
             }
             if(dp[n] != -1){
                 return dp[n];
             }

                int ans = suRM(n-1,dp) + suRM(n-2,dp);
                return dp[n]  = ans;
    }
    
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans = suRM( n,dp);
        return ans;
    }
};