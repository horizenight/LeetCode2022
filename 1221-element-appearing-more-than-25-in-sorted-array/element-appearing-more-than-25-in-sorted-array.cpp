class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // keep a map 
        // keep a count that calculates that it is more or less 
        unordered_map<int,int> mp;
        for(auto it : arr){
            mp[it]++;
        }
        int n = arr.size() * 0.25 ;

        for(auto it: mp){
            if(it.second > n) return it.first; 
        }
        return -1;
    }
};