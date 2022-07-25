class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
   
        vector<int>ans;
        
        for(int i= 0 ; i < nums.size();i++){
            if(nums[i] == 1){
                ans.push_back(i+1);
            } 
        }
        if(ans.empty()){
            return true;
        }
        
        for(auto it: ans){
            cout<<it<<" ";
        }cout<<endl;
        
        for(int i = 0 ; i <ans.size()-1;i++){
            if(ans[i+1] - ans[i]-1 < k ){
                return false;
            }
        }
        
        return true;
      
    }
};