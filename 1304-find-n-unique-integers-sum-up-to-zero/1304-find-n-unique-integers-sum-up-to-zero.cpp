class Solution {
public:
    vector<int> sumZero(int n) {
        
        
         vector<int> ans;
        for(int i = -n/2 ; i <0 ;i++ ){
            
            ans.push_back(i);
        }
        
         for(int i = n/2 ; i >0 ;i-- ){
            
            ans.push_back(i);
        }
        
        
        if(n&1){
            ans.push_back(0);
        }
     
               
           return ans;   
    }
};