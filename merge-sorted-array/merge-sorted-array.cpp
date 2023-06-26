class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m+n;
        for(int i = m ; i<total ; i++){
                nums1[i] = nums2[i-m];
        }

        return sort(nums1.begin(),nums1.end());
    }
};