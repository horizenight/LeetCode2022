class Solution {
public:

int solveMem(vector<vector<int>>&dp , string&s1,string&s2,int i ,int j){
    if( i== 0 ) return dp[i][j] = j ;
    if(j == 0 ) return dp[i][j] = i;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i-1] == s2[j-1]) return dp[i][j] = solveMem(dp,s1,s2,i-1,j-1) ; // last char matches then no operation required 
    else{
        int add = 1+ solveMem(dp,s1,s2,i,j-1);
        int replace = 1 + solveMem(dp,s1,s2,i-1,j-1);
        int remove = 1+ solveMem(dp,s1,s2,i-1,j);
        return dp[i][j] = min({add,replace,remove});
    }
}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveMem(dp,word1,word2,n,m);
    }
};