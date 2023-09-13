class Solution {
public:
    int solve(vector<int>&ratings){
        int n = ratings.size();
        int candy = n ; // each person should have one candy 
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            //increasing slope - Peak
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }

            // dip 
            int dip = 0 ;
            while(i< n && ratings[i] < ratings[i-1]){
                dip++;
                candy +=dip;
                i++;
                

            }

            candy -= min(peak,dip);
        }

        return candy;

    }
    int candy(vector<int>& ratings) {
        
        int ans = solve(ratings);
        return ans;

        // int n = ratings.size();
        // vector<int>L2R(n,1);
        // vector<int>R2L(n,1);

        // for(int i = 1; i < n;i++){
        //     if(ratings[i] > ratings[i-1]){
        //         L2R[i] = max(L2R[i] , L2R[i-1] + 1);
        //     }
        // }

        // for(int i = n-2 ; i >=0;i--){
        //      if(ratings[i] > ratings[i+1]){
        //         R2L[i] = max(R2L[i] , R2L[i+1] + 1);
        //     }
        // }

        // int result = 0;
        // for(int i = 0 ; i <n;i++){
        //     result += max(L2R[i],R2L[i]);
        // }
        
        // return result;
    }
};