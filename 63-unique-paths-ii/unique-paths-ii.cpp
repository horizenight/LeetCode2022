class Solution {
public:
 int soR(vector<vector<int>>& obstacleGrid,int m , int n){
        if(m == 1 && n == 1){
            return 1;
        }
        if (m <= 0 || n <= 0 ||obstacleGrid[m-1][n-1] == 1 ) {
        return 0;
            }
            
        int count = soR(obstacleGrid,m,n-1)  + soR(obstacleGrid,m-1,n);
        return count;
    }

    int soM(vector<vector<int>>& obstacleGrid,int m , int  n, vector<vector<int>> & dp){
         if(m == 1 && n == 1){
            return 1;
        }
        if (m <= 0 || n <= 0 ||obstacleGrid[m-1][n-1] == 1 ) {
        return 0;
            }
        if(dp[m][n] !=-1){
            return dp[m][n];
        }
        int count = soM(obstacleGrid,m,n-1,dp)  + soM(obstacleGrid,m-1,n,dp);
        return dp[m][n] = count;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 ){
            return 0;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans = soM(obstacleGrid,m,n,dp);
        return ans;
    }
};