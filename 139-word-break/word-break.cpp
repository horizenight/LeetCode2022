class Solution
{
    public:
       int solve(string s ,map<string,int>&mp, vector<int>&dp,int idx ){
        if(idx>= s.size()){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
        int ans = s.size();
        string currStr = "";
        for(int cI = idx ; cI<s.size() ;cI++){
            currStr.push_back(s[cI]);

            int count = ((mp.count(currStr)? 0 : currStr.size()) + solve(s,mp,dp,cI+1));
            ans = min(ans,count);
        }

        return dp[idx] = ans;

    }
            bool wordBreak(string s, vector<string> &wordDict)
            {
                vector<int> dp(s.length() + 1, -1);
                map<string,int> mp;
                for (string &words: wordDict) mp[words]++;
                int ans = solve(s, mp, dp, 0);

                if (ans == 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        };