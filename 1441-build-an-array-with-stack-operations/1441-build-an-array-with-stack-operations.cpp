class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int s = 0;
       
        for(int i = 1 ; i <=n ;i++){
            
            if(s<target.size()){
                ans.push_back("Push");
                if( i == target[s]){
                s++;
            }else{
                ans.push_back("Pop");
            }
            
            }
            
            
        }
        
        return ans;
       
    }
};