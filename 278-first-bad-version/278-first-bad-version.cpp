// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
//         we want first occurance of bad 
        
        int s =0;
        int e = n;
        int index =-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(isBadVersion(mid)){
                index = mid;
                e = mid-1;
                
            }
            else{
                s = mid+1;
            }
        }
        return index;
    }
};