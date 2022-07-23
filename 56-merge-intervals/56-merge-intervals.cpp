class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> final;
      
        
           
        if(intervals.size()==0) 
            return final;
        
        sort(intervals.begin(),intervals.end());
        
        vector <int> temp = intervals[0];
      
        
        for(auto it : intervals){
            
            if(it[0]<=temp[1]){
//                 overlap 
                
                temp[1]=max(it[1],temp[1]);

            }
            else{
                final.push_back(temp);
                temp = it ; 
            }
            
            
            
            
            
            

            
        }
              final.push_back(temp);
            return final;
    }
        
        
        
            
            
            
            
    
};