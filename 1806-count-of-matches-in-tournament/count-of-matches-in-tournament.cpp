class Solution {
public:
    int numberOfMatches(int n) {
        int match  = 0;
        while(n > 1){
            if(!(n&1)){
                // n is even 
               int matchcount=n/2;
               n=n/2;  
               match+=matchcount;
            }else{
                int matchcount=(n-1)/2;
                 n=matchcount+1; 
                 match+=matchcount;  
            }
        }


        return match;
    }
};

// Recursive 
// class Solution {
// public:

//     int numberOfMatches(int n) {
//         if(n== 1) return 0;
//         if(n&1){
//             // n is odd 
//             return  ( (n - 1) / 2 )  + numberOfMatches((n - 1) / 2 + 1);
//         }else{
//             return (n/2) + numberOfMatches(n/2);
//         }
//     }
// };

