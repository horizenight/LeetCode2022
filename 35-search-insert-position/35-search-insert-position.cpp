class Solution {
    private:
    int BS(vector<int>& nums, int target){
        
            
        int s = 0 ;
        int e = nums.size()-1;
        
        int mid = s + (e-s)/2;
        int index = -1;
        while(s<=e){
            mid = s + (e-s)/2;
            if(nums[mid] ==target){
                cout<<mid<<endl;
                index = mid ;
                break;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            
            
            
        }
        
        return index;
        
    }
public:
    int searchInsert(vector<int>& nums, int target) {
    
        int index = BS(nums,target);
        
        if(index ==-1){
            nums.push_back(target);
            sort(nums.begin(),nums.end());
            
            int ans = BS(nums,target);
            return ans;
            
        }
            
        
        
        
        return index ;

        
        
        
    }
};