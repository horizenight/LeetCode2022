class Solution {
public:
    int soR(int m , int n){
        if(m == 1 && n == 1){
            return 1;
        }
        if (m <= 0 || n <= 0) {
        return 0;
            }
        
        int count = soR(m,n-1)  + soR(m-1,n);

        return count;
    }

    int soM(int m ,int  n,vector<vector<int>>& dp){
        if(m == 1 && n == 1){
                    return 1;
                }
        if (m < 0 || n < 0) {
                return 0;
                    }

        if(dp[m][n] != -1){
            return dp[m][n];
        }
                
        int count= soM(m,n-1,dp)  + soM(m-1,n,dp);

        return dp[m][n] = count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = soM(m,n,dp);
        return ans;
    }
};