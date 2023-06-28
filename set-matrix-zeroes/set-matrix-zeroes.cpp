class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
          set<int> rows0;
        set<int> cols0;
        
        int cols = matrix[0].size();
        int rows = matrix.size();
        
        
        for(int row= 0 ; row < rows;row++){
            for( int col = 0 ; col <cols ; col++){
                
                if(matrix[row][col]==0){
                   
                    rows0.insert(row);
                    cols0.insert(col);
                    
                }   
            }   
        }
        
        
//     replace all rows with zero 
        
        for( auto i : rows0){
            for(int col = 0 ; col<cols; col++){
                matrix[i][col]= 0;
            }
        }
        
        
        for(auto i : cols0){
            for(int row = 0 ; row<rows;row++){
                matrix[row][i] = 0;
            }
            
            
        }
        
        
        
        
    }
};