class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int prevlast = points[0][1];
        int count =0;
        for( int i = 1; i<points.size();i++){
            if(prevlast >= points[i][0]){
                if(prevlast > points[i][1]){
                    prevlast = points[i][1];
                }
            }
            else{
                prevlast = points[i][1];
                count++;
            }
        }

        return count+1;
    }
};