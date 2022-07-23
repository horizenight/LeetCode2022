class Solution {

public:
    vector<int> getRow(int rowIndex) {
//         only row required
        int n = rowIndex;
        vector<int> ans(rowIndex+1);
        long long int res = 1;
        ans[0]=1;
       
        for(int i = 0 ; i < n ;i++){
          
            res *= (n-i);
            res /=(i+1);
            ans[i+1]= res;
        }
        return ans;
    }
};