class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       vector<vector<int>> result(2);
       unordered_map<int,pair<int,int>> mp;

   

       for(auto it : matches){
        //    for(auto i: it){
               int winner = it[0];
               int loser =  it[1];

               mp[winner].first++;
               mp[loser].second++;
           }
        
    //        // map created 
           for(auto it: mp){
               if(it.second.second == 0){
                result[0].push_back(it.first);
               }
               if(it.second.second == 1){
                result[1].push_back(it.first);
               }
           }

        sort(result[0].begin(),result[0].end());
        sort(result[1].begin(),result[1].end());

                       
        return result;
       }

       // not lost anny is easy that it does not show on the right side 
       // lost one time is win and loss count is mapped 
    
};