class Solution {
public:
    int depth = 0 ;
    int minOperations(vector<string>& logs) {
        for(auto log : logs){
            if(log == "../"){
                if(depth == 0) continue;
                depth--;
            }
            else if(log == "./"){
                continue;
            }
            else{
                depth++;
            }
        }

        return depth;
    }
};