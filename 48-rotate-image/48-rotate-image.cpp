class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        
//         transpose 
        int cols = matrix[0].size();
        int rows = matrix.size();
        
        
 for(int row = 0 ; row<rows; row++){
   for(int j =0 ; j<row ; j++){
                swap(matrix[row][j], matrix[j][row]);
            }
        }
        
//         reflect 
      for(int i=0;i<matrix.size();i++){
            
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
        
        
        
        

};