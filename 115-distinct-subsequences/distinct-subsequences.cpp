class Solution
{
    public:
        int solveR(string &s, string &t, int i, int j)
        {
            if (j == t.length()) return 1;
            if (i == s.length()) return 0;
            int ans = 0;
            if (s[i] == t[j])
            {
                ans += solveR(s, t, i + 1, j + 1);
            }
            ans += solveR(s, t, i + 1, j);

            return ans;
        }

    int solveTD(string &s, string &t, int i, int j, vector<vector < int>> &dp)
    {
        if (j == t.length()) return 1;
        if (i == s.length()) return 0;
        int ans = 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s[i] == t[j])
        {
            ans += solveTD(s, t, i + 1, j + 1, dp);
        }
        ans += solveTD(s, t, i + 1, j, dp);

        return dp[i][j] = ans;
    }

    int solveBU(string &s, string &t)
        {
            vector<vector < int>> dp(s.length() + 1, vector<int> (t.length() + 1, 0));
            for (int i = 0; i <= s.length(); i++)
            {
                dp[i][t.length()] = 1;
            }

            for (int i = s.length() - 1; i >= 0; i--)
            {
                for (int j = t.length() - 1; j >= 0; j--)
                {   
                    long long ans = 0;
                    if (s[i] == t[j])
                    {
                        ans += dp[i+1][j+1];
                    }
                    ans += dp[i+1][j];

                    dp[i][j] = ans;
                }
            }

            return dp[0][0];
        }
        int numDistinct(string s, string t)
        {
           	// LCS but now we count the ways
            if (t.length() > s.length())
            {
                return 0;
            }
            vector<vector < int>> dp(s.length() + 1, vector<int> (t.length() + 1, -1));
            // int ans = solveTD(s, t, 0, 0, dp);
            int ans = solveBU(s,t);
            return ans;
        }
    };