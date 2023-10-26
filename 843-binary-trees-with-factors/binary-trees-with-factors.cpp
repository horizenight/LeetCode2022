class Solution {
public:
    // similar to LIS 
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        //Intution 
        // 4 2 5 10 
        // sort 
        // map 
        // i , j < i 
        // multiply root = arr[i]  , LC = arr[j] RC = root/LC 
        // mp[root] += mp[LC] * mp[RC]; 

        int n = arr.size();
        sort(arr.begin() , arr.end());
        unordered_map<int,long long> mp;
        mp[arr[0]] =1;
        for(int i =1; i<n;i++){
            int root = arr[i];
            mp[root] = 1;

            for(int j = 0 ; j<i;j++){
                int LC = arr[j];
                if(root%LC == 0  && mp.find(arr[i]/LC) != mp.end()){
                    mp[root] += mp[LC] * mp[ (arr[i]/LC) ];
                }
            }

        }

        int result = 0;
        for(auto &it: mp){
            result = (result + it.second )  % MOD;
        }
        

        return result;
    }
};