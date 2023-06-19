class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans(gain.size()+1,0);

        for(int i = 1 ; i < ans.size() ; i++){
            ans[i] = ans[i-1] + gain[i-1];
        }
        // for(auto it: ans){
        //     cout<<it<<" ";
        //             }
        return *max_element(ans.begin() , ans.end());
    }
};