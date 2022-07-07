class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int fsum = 0; 
        for(int i = 0 ; i<nums.size();i++){
            sum = sum + nums[i];
           
        }
        for(int i =0 ; i <nums.size()+1;i++){
             fsum = fsum + i ;
            cout<<fsum;
        }
      
        
                return fsum-sum;
    }
};