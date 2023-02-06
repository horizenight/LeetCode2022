class Solution {

public:
    bool divisorGame(int n) {
        if(n&1){
            // odd 
            return false;
        }
        return true;
    }
};