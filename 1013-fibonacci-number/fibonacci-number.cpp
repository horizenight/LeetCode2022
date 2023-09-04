class Solution {
public:
   

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
    
    int suT(int n ){
        vector<int> dp(n+1,0);
        if(n <=1){
            return n;
        }
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2;i<= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int suTSO(int n){
        if(n <= 1){
            return n;
        }
        int prev2 = 0;
        int prev1 = 1;
        int ans;
        for(int i = 2;i<= n ; i++){
            ans = prev1 + prev2;
            // shift 
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
    
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans = suTSO( n);
        return ans;
    }
};