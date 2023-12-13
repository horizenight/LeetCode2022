class Solution {
public:
    bool checkRow(vector<vector<int>>& mat,int i){
        int count = 0;
        for(int j = 0 ;j<mat[0].size();j++){
            if(mat[i][j] == 1) count++;
        }
        if(count>1) return false;
        return true;
    }
    bool checkColumn(vector<vector<int>>& mat,int j){
        int count = 0;
        for(int i = 0 ;i<mat.size();i++){
            if(mat[i][j] == 1) count++;
        }
        if(count>1) return false;
        return true;
    }
    bool check(int i ,int j ,vector<vector<int>>& mat ){
        return checkRow(mat,i) && checkColumn(mat,j);
    }
    int numSpecial(vector<vector<int>>& mat) {
        int count  = 0 ;
        int special = 0;
        for(int i =0 ;i<mat.size();i++){
            for(int j = 0 ; j <mat[i].size();j++){
                if(mat[i][j] == 1){
                    if(check(i,j,mat)) special++;
                }
            }
        }
        return special;
    }
};