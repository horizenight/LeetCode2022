class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m-1;
        int b = n-1;
        int c = m+n-1;

        if(m == 0){
            for(int i =0 ; i<n ; i++){
                nums1[i] = nums2[i];
            }
            return ;
        }

        while(a >= 0 && b >= 0 ){
            if(nums1[a] <= nums2[b]){
                // b is greater 
                nums1[c] = nums2[b];
                b--;
                c--;
            }
            else{
                // nums1 is greate r 
                nums1[c] = nums1[a];
                a--;
                c--;
            }
        }
        cout<<a << " " << b ;
        if(b >= 0){
            // nums1 has some unsorted left 
            for(int i = 0 ; i<=b;i++){
                nums1[i] = nums2[i];
            }
        }


    }
};