class Solution {
    private:
    int Dbs(vector<int>& nums, int target){
        int e = nums.size()-1;
        int s = 0 ;
        int index = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(nums[mid] == target){
                index = mid;
                
            }
          if(nums[mid]<=target){
                s = mid+1;
            }
            else{
             e = mid-1;
            }
            
            
            
        }
                   // cout<<index<<" "<<endl;
        return index;
    }
       int Fbs(vector<int>& nums, int target){
        int e = nums.size()-1;
        int s = 0 ;
        int index = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(nums[mid] == target){
                index = mid;
                
            }
            if(nums[mid]>=target){
                e = mid -1;
            }
            else{
               s = mid+1;
            }
            
            
            
        }
           // cout<<index<<" "<<endl;
           return index;
    }
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int first_occurance = Fbs(nums,target);
                    int second_occurance = Dbs(nums,target);
            
            vector<int>ans;
        if(first_occurance == -1 || second_occurance == -1){
            return ans;
        }
        for(int i = first_occurance ; i <=second_occurance;i++ ){
            ans.push_back(i);
        }
        
        return ans;

    }
};