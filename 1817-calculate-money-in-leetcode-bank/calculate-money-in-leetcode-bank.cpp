class Solution {
public:
    int totalMoney(int n) {
        if(n == 0 ) return 0; 
        vector<int>arr(n+1,0); // can see prefix sum 
        arr[0] = 1; // Monday : 0 M , 1 T , 2 W , 3 Th ,4 F ,6 Sat ,7 Sun , 8th Mon , 9 th Tue
        for(int i = 1 ; i <n ; i++){
            if( i % 7 != 0 ){
                arr[i ] = arr[i-1] + 1;
            }
            else{
                arr[i] = arr[i-7] + 1;
            }
        }
        int sum = 0;
        for(auto it : arr){
            sum += it;
        }
        return sum;
    }
};