class Solution {
    private:
   void solve(vector<int>& nums,int n){
        
        vector<int> ans(n-1) ;
//         base case 
        if(n==1){
           
            
            return ;
        }

        for(int i =0;i<n-1;i++){
            ans[i] = (nums[i]+nums[i+1])%10;
        }
    
       nums = ans ;
        solve(nums,n-1);
        
        
    }
    
public:
    int triangularSum(vector<int>& nums) {
//         pascal sum 
//         look out for which index to add do it by permutation

        
    solve(nums,nums.size());
        
  
        
        return nums[0];
    }
};