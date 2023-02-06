class Solution {
    private:
   static bool sortByVal(const pair<int, int> &a, 
               const pair<int, int> &b) 
{ 
    return (a.second > b.second); 
} 
   
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m ;

        for(auto i : nums){
            m[i]++;
        }

        vector<pair<int,int>> v;

        for(auto &it : m){
            v.push_back(it);
        }

        sort(v.begin(),v.end(),sortByVal);
        

        for (auto i : v)
        cout << i.first << " : " << i.second << "\n";

        vector<int>ans;
        for(int i = 0 ; i < k ;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};