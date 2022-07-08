class Solution {
public:
    int minimumSum(int num) {
        vector<int>ans;
        
        while(num>0){
           
            int lnum = num%10; //lastdigit
            num = num/10;
            
            ans.push_back(lnum);
            
        }
        
       sort(ans.begin(),ans.end());
        
        int minSum = 0;
        
        minSum = (ans[0]*10 + ans[2]) + (ans[1]*10 + ans[3]);
        
        
        return minSum;
    }
};