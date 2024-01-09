class Solution {
public:
    int minOperations(vector<int>& nums) {
        // delete two equal elements or delete three equal elements 
       // approach : 
       // first find if its possible to delete the array : that is each freuqency should be divisble by 2 or not 2 : return 1 if we cannot 

       // 2 : 4 , 3 : 3 , 4 : 2 
       unordered_map<int,int> mp;
       for(auto i : nums){
           mp[i]++;
       }
            int count =0;
        for(auto a : mp){
            int n = a.second;
            if(n==1) return -1;
            count+= n/3;
            if(n%3) count++;
        }
        return count;
    }
};