class Solution
{
    public:
        int soR(string &a, string &b, int i, int j)
        {
            if (i == a.length())
            {
                return b.length() - j;
            }
            if (j == b.length())
            {
                return a.length() - i;
            }

            int ans = 0;
            if (a[i] == b[j])
            {
                return soR(a, b, i + 1, j + 1);
            }
            else
            {
                int insert = 1 + soR(a, b, i, j + 1);
                int remove = 1 + soR(a, b, i + 1, j);
                int replace = 1 + soR(a, b, i + 1, j + 1);
                ans = min(min(insert, remove), replace);
            }

            return ans;
        }

    int soT(string &a, string &b)
    {
        vector<vector < int>> dp(a.length() + 1, vector<int> (b.length() + 1, 0));

        // for last row 
        for(int j = 0 ; j <=b.length() ; j++){
            dp[a.length()][j] = b.length() - j;
        }
        // for last column
        for(int i = 0 ; i <=a.length() ; i++){
            dp[i][b.length()] = a.length() - i;
        }

        for (int i = a.length()-1; i >= 0; i--)
        {
            for (int j = b.length()-1; j >= 0; j--)
            {
       
                if (a[i] == b[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                    int insert = 1 + dp[i][j+1];
                    int remove = 1 +dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    dp[i][j] = min(min(insert, remove), replace);

                }
            }
        }

        return dp[0][0];
    }

    int seO(string &a , string &b ){
        vector<int> curr(b.length()+1 , 0);  //dp[i]
        vector<int> next(b.length()+1 , 0);   //dp[i+1]

       for (int j = b.length() - 1; j >= 0; j--) {
        next[j] = b.length() - j;
    }

        for (int i = a.length()-1; i >= 0; i--)
        {
            for (int j = b.length()-1; j >= 0; j--)
            {   
                curr[b.length()] = a.length()-i;
       
                if (a[i] == b[j])
                {
                    curr[j] = next[j+1];
                }
                else
                {
                    int insert = 1 + curr[j+1];
                    int remove = 1 +next[j];
                    int replace = 1 + next[j+1];
                    curr[j] = min(min(insert, remove), replace);

                }
                
            }
            //shift 
                next = curr; 
        }
        return curr[0];
    }
    int minDistance(string a, string b)
    {
        if (a.length() == 0)
        {
            return b.length();
        }
        if (b.length() == 0)
        {
            return a.length();
        }

        int ans = seO(a, b);
        return ans;
    }
};