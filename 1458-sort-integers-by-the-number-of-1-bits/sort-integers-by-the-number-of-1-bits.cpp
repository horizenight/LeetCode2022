class Solution {
public:
    int find1BitCount(int num){
        int count = 0;
        while(num!= 0){
            if(num&1){
                count++;
            }
            num>>=1;
        }

        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        // sort function using lambda comperator 
        // auto lambda = [ &a ](int a , int b) { body }
        // [ ] // capture clause BY reference extra copy wouldnt be taken
        // ( ) // receiving parameters 
        // int countOneA = find1BitsCount(a);
        // int countOneB = findbitsCount(b); 
        // if(cA == cB) return a < b;
        // return cA<CB;

        auto lambda = [&](int &a , int &b){
            // int count_a = find1BitCount(a);
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);

            if(count_a == count_b){
                return a<b;
            }

            return count_a<count_b;

        };

        sort(begin(arr),end(arr),lambda);
        return arr;

    }
};