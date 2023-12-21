class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int max_dist = INT_MIN;
        for(int i =0;i<points.size()-1;i++){
            int a = points[i][0];
            int b = points[i+1][0];

            max_dist = max(max_dist,abs(a-b));
        }

        return max_dist;
    }
};