class Solution {
public:
    int solveUsingRecursion(string a , string b , int i , int j){
        if(i == a.length() || j == b.length()){
            //no string left to traverse 
            return 0;
        }
        int ans =0;
        if(a[i] == b[j]){
            ans = 1 + solveUsingRecursion(a,b,i+1,j+1);
        }
        else{
            ans = 0 + max(solveUsingRecursion(a,b,i+1,j) , solveUsingRecursion(a,b,i,j+1));
        }

        return ans;
    }
    int solveUsingMem(string& a , string&  b , int i , int j , vector<vector<int>> &dp){
        if(i == a.length() || j == b.length()){
                    //no string left to traverse 
                    return 0;
                }
            if(dp[i][j] != -1){
                return dp[i][j];
            }
                
            int ans =0;
            if(a[i] == b[j]){
                ans = 1 + solveUsingMem(a,b,i+1,j+1,dp);
            }
            else{
                ans = 0 + max(solveUsingMem(a,b,i+1,j,dp) , solveUsingMem(a,b,i,j+1,dp));
            }
            return dp[i][j] = ans;
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(text1.size() + 1 , vector<int> (text2.size()+1 , -1));
        int ans = solveUsingMem(text1, text2, 0, 0,dp);

        return ans;
    }
};