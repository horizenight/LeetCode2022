class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(arr.size() == 1) return arr[0];
        double condition = 0.25 * arr.size();
        int freq=1;
        for(int i = 1 ; i<arr.size() ; ++i){
            if(arr[i] == arr[i-1]){
                ++freq;
                if(freq>condition){
                    return arr[i];
                    }
            }
            else{
                freq=1;
            }
        }

        return -1;
    }
};