class Solution {
//     used 
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       int n = nums.size();
        sort(nums.begin(),nums.end());
        int subset_ct = (1<<n);
        vector<vector<int>> subsets;
        for(int mask = 0 ;mask < subset_ct;++mask){
            vector<int>subset;
            for(int i = 0 ;i<n;i++){
                if((mask  & (1<<i) )!= 0 ){
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }
        sort(subsets.begin(),subsets.end());
         subsets.erase( unique( subsets.begin(), subsets.end() ), subsets.end() );
return subsets;
    }
        
              
    
};