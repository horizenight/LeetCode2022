class Solution {
public:
    int solveR(vector<int>&dp,string s , int index ){
        if(index == s.length()) return 1;
        if(s[index] == '0'){
            return 0; 
        }
        if(dp[index] != -1 ) return dp[index];
        int ways = solveR(dp,s,index+1);
        if(index+1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))){
            ways += solveR(dp,s,index+2);
        }

        return dp[index] =  ways;
        // num should be less then 1, 2, and 6 
    }
    int numDecodings(string s) {
        // direction : string of numbers decode it in any way 
        // 11106 : 2 number groupd could be there and max 
        // 1 way : if 0 is; not there 
        vector<int>dp(s.size()+1,-1);
        return solveR(dp,s,0);
    }
};