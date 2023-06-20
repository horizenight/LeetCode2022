class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        
        // observation windows starts with kand runs for i -k -1
        vector<long long int> ans(nums.size() ,-1 );
        vector<int> ans3(nums.size(),-1);
        vector<int> ans2;


        // handeling edge cases 
        if(k==0){
            return nums;
        }

        if(nums.size() <= k+1){
            // window no 
            return ans3;
        }

        long long int temp = 0;
        long long int radius = 2*k +1;
        for(int i = 0 ; i <=k ; i++){

            temp += nums[i] + nums[k+i];
        }
        ans[k] = temp-nums[k];
        
        for(int i = k+1 ; i<nums.size()-k;i++){
            ans[i] = ans[i-1]-nums[i -k -1] +nums[k+i];
        }
             for(int i = k ; i<nums.size()-k;i++){
            ans[i]= ans[i]/radius;
        }
        for(auto it : ans){
ans2.push_back(it);
        }
        

        
       return ans2;
    }
};