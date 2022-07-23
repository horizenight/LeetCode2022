class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//         like kandane algo 
        
      if(nums.empty()){
          return 0;
      }
        
          set<int> s;
        for(int i =0 ; i <nums.size();i++){
            s.insert(nums[i]);
            
        }
    int max_count = 1;
        int count = 1 ;
        nums.clear();
        for(auto it :s){
            nums.push_back(it);
        }
        
   
        int start = nums[0];
       
        for(int i= 0 ; i < nums.size();i++){
            if(start+1 == nums[i] ){
                count++;
                start = start +1;
                cout<<start<<" ";
                
            }
            else{
             
                count  =1 ; 
               
                start = nums[i];

            }
               max_count = max(count,max_count);
            }
        return max_count;

    }
};