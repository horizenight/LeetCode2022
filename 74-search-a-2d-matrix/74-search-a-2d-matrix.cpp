class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         sorted way matrix threfore binary search
        
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end = row*col -1;
        
        int mid = start + (end-start)/2;
        //we have mid co ordinate in 1d representation 
        
        
        while(start<=end){
            
            int element = matrix[mid/col][mid%col];
            //this is most crucial 
            
            if(element == target ){
                return 1;
            }
            if(element<target ){
                start = mid +1;
            }else{
                end = mid -1;
                
            }
            
            mid = start + (end-start)/2;
            
            
        }
        
        return 0;
        
        
    }
};