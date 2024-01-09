class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // somthing like buckets 
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        int maxi = -1;
        for(auto it: mp){
            maxi = max(maxi,it.second);
        }
        vector<vector<int>>ans;
        // now we know at least maxi buckets will be there 

        // this should run unitll 
        for(int i =0 ;i <maxi;i++){
            vector<int>temp;
            for(auto &it:mp){
                if(it.second > 0){
                    temp.push_back(it.first);
                    it.second--;
                }
            }
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};