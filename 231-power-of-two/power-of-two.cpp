class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1; 
        if(n == 1 ) return true;
        for(int i = 0 ; i <= 30 ;i++){
            
             if(ans < INT_MAX /2 ){
                ans = ans * 2;
                cout<<ans<<endl;
            }
            if(ans == n) return true;
           
        }

       

        return false;
    }
};