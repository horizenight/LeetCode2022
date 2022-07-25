class Solution {
    private:
    int binarySearchLower(vector<int>& nums, int target){
        int e = nums.size()-1;
        int s = 0;
        int Lindex = -1; 
        while(s<=e){
            int mid = s +(e-s)/2;
            
            if(nums[mid] == target){
                Lindex =mid;
             
            }
            if(nums[mid]>=target){
                e = mid-1;
            }else{
                s = mid+1;
            }
            
            
            
            
            
        }
        return Lindex;
        
    }
    
     int binarySearchUpper(vector<int>& nums, int target){
        int e = nums.size()-1;
        int s = 0;
        int Lindex = -1; 
        while(s<=e){
            int mid = s +(e-s)/2;
            
            if(nums[mid] == target){
                Lindex = mid;
               
            }
            if(nums[mid]<=target){
                s = mid+1;
            }else{
               e = mid-1;
            }
            
            
            
            
            
        }
        return Lindex;
        
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        int last =  binarySearchUpper(nums,target);
        int first =   binarySearchLower(nums,target);
        
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
        
    }
};