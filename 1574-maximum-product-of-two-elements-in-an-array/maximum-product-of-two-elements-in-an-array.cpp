class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // two loops then check max value : Brute Force 
        int product = 0;
        for(int i = 0 ; i<nums.size();i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                product = max(product,(nums[i]-1)*(nums[j]-1));
            }
        }

        return product;
    }
};