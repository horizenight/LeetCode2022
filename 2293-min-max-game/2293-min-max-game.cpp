class Solution {
    private:
    void solve(vector<int>&nums,int n){
        if(n==1){
            return ;
            
        }
        vector<int> newNums(n/2);
        for(int i = 0 ; i < n/2 ; i ++){
            
            if(i&1){
            //odd
                newNums[i]=max(nums[2 * i], nums[2 * i + 1]);
            
        }else{
             
                
                newNums[i]=min(nums[2 * i], nums[2 * i + 1]);
        }
            
        }
        
        nums = newNums;
        solve(nums,n-1);
        
    }
public:
    int minMaxGame(vector<int>& nums) {
        
        solve(nums,nums.size());
        
        return nums[0];
    }
};