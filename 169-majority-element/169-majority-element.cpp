class Solution {
    //boore moore algorithm
public:
    int majorityElement(vector<int>& nums) {
        int count = 0 ;
        int major = 0;
        
        for(auto it:nums){
            if(count ==0){
                major = it;
            }
            if(it == major){
                count+=1;}
            
            else{
                count -=1;
            }
        }
        
        return major;
    }
};