class Solution {
private:
    int solveUsingRecursion(vector<int>& arr, map<pair<int,int>, int>& maxi, int left, int right) {
        if (left >= right) {
            // single element or no element in the range
            return 0;
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solveUsingRecursion(arr, maxi, left, i) + solveUsingRecursion(arr, maxi, i+1, right));
        }

        return ans;
    }

    int solveUsingMem(vector<int>& arr, map<pair<int,int>, int>& maxi, int left, int right,vector<vector<int>>& dp){
        //
          if (left >= right) {
            // single element or no element in the range
            return 0;
        }
        if(dp[left][right]!= -1){
            return dp[left][right];
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solveUsingMem(arr, maxi, left, i,dp) + solveUsingMem(arr, maxi, i+1, right,dp));
        }
        
        return dp[left][right] = ans;
    }


    int solveUsingTab(vector<int>&arr,map<pair<int,int>, int>& maxi){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        //base case 
        for(int left = n-1 ; left >= 0 ; left--){
            for(int right = 0 ; right <= n-1 ;right++){
                if(left >= right){
                    //invalid or single element 
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for (int i = left; i < right; i++) {
                        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]); 
                        }
                    dp[left][right] = ans;
                }
            }
        }
    return dp[0][n-1];
    }
public:

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int> maxi;

        // pre computation
        // in pre computation we compute the maxi on each range
        for (int i = 0; i < arr.size(); i++) {
            maxi[{i, i}] = arr[i]; // single element
            for (int j = i+1; j < arr.size(); j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
                // this stores the max between the range {i, j}
            }
        }

        int n = arr.size();
        // int ans = solveUsingRecursion(arr, maxi, 0, n-1);

        // intialising dp 
        vector<vector<int>> dp(n+1,vector<int>( n+1 , -1));
        int ans = solveUsingTab(arr,maxi);

        return ans;
    }
};
