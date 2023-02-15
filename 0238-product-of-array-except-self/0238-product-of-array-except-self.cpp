class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> prefixProduct(nums.size()+1 ,1);
        vector<int> suffixProduct(nums.size()+1,1);


        for(int i = 1 ; i < nums.size() ;i++){
            suffixProduct[i] = suffixProduct[i-1] * nums[i-1];
           // prefixProduct[i] = prefixProduct[i+1] * nums[i+1];
        }

        for(int i = nums.size() - 2 ; i >= 0 ;i--){
            prefixProduct[i]  = prefixProduct[i+1] * nums[i+1];
        }


        for(auto it : suffixProduct){
            cout<< it<<" ";
        }
        cout<<endl;

            for(auto it : prefixProduct){
            cout<< it<<" ";
        }
        cout<<endl;

        for(int i = 0 ; i<nums.size() ;i++){
            nums[i] = suffixProduct[i] * prefixProduct[i];
        }


        return nums ;
    }
};