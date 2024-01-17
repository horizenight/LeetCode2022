class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int>mp;
        for(auto i : arr){
            mp[i]++;
        }

        vector<int>freq;
        for(auto it : mp){
            freq.push_back(it.second);
        }

        sort(freq.begin(),freq.end());

        for(int i = 1; i <freq.size();i++){
            if(freq[i] == freq[i-1]){
                return false;
            }
        }
        return true;
    }
};