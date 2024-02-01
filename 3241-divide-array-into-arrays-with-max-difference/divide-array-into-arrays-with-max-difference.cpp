class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // logic: traverse each nums in sorted way : if anyway fails return []
        //[1,3,4,8,7,9,3,5,1] k =2 
        //[1,1,3,3,4,5,7,8,9]  
        // i =0 -> ( abs(arr[i] - arr[i+1]) <=k temp.push(arr[i]) ) while temp.size()<3 and check a flag of abs if flag violated errturn empty ptherwise reuturn ans
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i = 2; i < nums.size(); i += 3){
            if(nums[i] - nums[i - 2] <= k) ans.push_back({nums[i-2], nums[i-1], nums[i]});
            else return {};
        }
        return ans;
        
    }
};