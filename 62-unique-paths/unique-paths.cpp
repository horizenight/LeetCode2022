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

    int soT(int m ,int n){
        vector<vector<int>>dp(m+2,vector<int>(n+2,1));
      
        for(int i = 1; i<m ; i++){
            for(int j = 1; j<n;j++){
                dp[i][j]  = dp[i][j-1] + dp[i-1][j];
            }
        }

        return dp[m-1][n-1];
    }

    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = soT(m,n);
        return ans;
    }
};