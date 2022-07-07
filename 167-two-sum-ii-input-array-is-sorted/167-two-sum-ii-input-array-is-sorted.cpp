class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         we will keep two pointer 
        
        vector<int>ans;

     int i = 0;
        int j = nums.size()-1;
       
        
        while(i<=j){
            int sum = nums[i] + nums[j];
          
            if(sum > target ){
                j--;
            }
            else if (sum < target ){
                i++;
            }
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            
            
        }
   
        
    
        return ans;
    }
};