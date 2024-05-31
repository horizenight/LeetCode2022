class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // on number once and alll other elements twice 
        // xor will contain two number which are twice 
        vector<int>ans(2,0);
        int xor2no = 0;
        for(int num:nums){
                xor2no ^= num;
        }

        unsigned int lowestBit = xor2no & -(unsigned int) xor2no;
        for(int num : nums){
            if((lowestBit & num ) == 0){
                ans[0] ^= num;
            }
            else{
                ans[1] ^= num;
            }
        }
        return ans;
    }
};