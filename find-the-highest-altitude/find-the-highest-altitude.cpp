class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans(gain.size()+1,0);
        int maxy = 0;
        for(int i = 1 ; i < ans.size() ; i++){
            ans[i] = ans[i-1] + gain[i-1];
            if(ans[i] > maxy){
                maxy= ans[i];
            }
        }

        
        // for(auto it: ans){
        //     cout<<it<<" ";
        //             }
        return maxy;
    }
};