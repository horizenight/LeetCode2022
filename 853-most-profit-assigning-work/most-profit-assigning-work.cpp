class Solution {
public:
    int max_profit =0 ;
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& workers) {
        int n = difficulty.size();
        int m = workers.size();
        for(int i =0 ;i <m ;i++){
            int worker_d = workers[i];
             int local_profit = 0;
            for(int j = 0 ;j <n;j++){
               
                if(difficulty[j] <= worker_d){
local_profit = max(local_profit,profit[j]);
                }
            }
            max_profit+= local_profit;

        }

        return max_profit;
    }
};