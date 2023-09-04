class Solution {
public:
    int soRM(string &a ,string &b,int i , int j ,vector<vector<int>> &dp){
        if( i == a.length()){
            return 0;
        }
        if(j == b.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(a[i] == b[j]){
            return dp[i][j] = 1 + soRM(a,b,i+1,j+1,dp);
        }
        else{
            return dp[i][j] = 0 + max(soRM(a,b,i+1,j,dp) , soRM(a,b,i,j+1,dp));
        }

    }
    int longestPalindromeSubseq(string s) {
        int i = 0 ;
        int j = 0;
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));
        string sRev = s ;
        reverse(sRev.begin(),sRev.end());
        int ans = soRM(s,sRev,i,j,dp);
        return ans;
    }
};