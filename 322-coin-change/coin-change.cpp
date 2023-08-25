class Solution {
public:
int coinChangeDP(vector<int> &coins, int amount)
{
    int n = coins.size();
    // initialising dp ;
    int **dp;
    dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[amount + 1];
        for (int j = 0; j <= amount; j++)
        {
            dp[i][j] = -1; // Initialize each cell with -1
        }
    }

    // intialsing values for dp
    //  1st row
    for (int j = 0; j <= amount; j++)
    {
        dp[0][j] = INT_MAX - 1;
    }
    // 1 st column
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    // if diviisble then if not then INT_MAX -1
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j % coins[0] == 0)
            {
                dp[i][j] = j / coins[0];
            }
            else
            {
                dp[i][j] = INT_MAX - 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if(coins[i-1] <=j ){
                dp[i][j] = min(1 + dp[i][j - coins[i-1]] , dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // solving dp 
    

    return dp[n][amount];
}

    int coinChange(vector<int>& coins, int amount) {


        int ans = coinChangeDP(coins,amount);
        if(ans == INT_MAX-1){
            return -1;
        }else{
            return ans;
        }
        
    }
};