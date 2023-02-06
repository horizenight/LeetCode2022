class Solution {
    private:
        static bool cmp(pair<int,int> &a , pair<int,int>&b){
        return a.second < b.second ;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int> mp ;
        for(auto it : nums){
            mp[it]++;
        }

 
        sort(nums.begin(),nums.end(),[&](int a,int b)->bool{
       return (mp[a]!=mp[b] ? mp[a]<mp[b] : a>b);
   });
   return nums;
}


    
};


