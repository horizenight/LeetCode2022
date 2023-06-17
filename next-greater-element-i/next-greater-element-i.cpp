class Solution {
    private:
   void solve(vector<int>& nums2 , vector<int> & ans){
        int n = nums2.size();
        stack<int> st;
        st.push(-1);

        for(int i = nums2.size() -1 ; i >= 0 ; i--){
            
             while (st.top() != -1 && nums2[st.top()] <= nums2[i]) {
                st.pop();
            }
            if (st.top() == -1) {
                ans[i] = -1;
            } else {
                ans[i] = nums2[st.top()];
            }
            st.push(i);


        }


    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans(nums2.size() ,-1);
        vector<int> ans2;
        // now we get the desired value from the ans [3,4,-1,-1] nums1 [4,1,2] nums2 [1,3,4,2]
        solve(nums2,ans);

        for(int i = 0 ; i < nums1.size() ; i++){
            int num1 = nums1[i]; //4

            for(int j = 0 ; j<nums2.size() ; j++){
                int num2 = nums2[j]; //1

                if(num1 == num2){
                    ans2.push_back(ans[j]);
                }
            }
        }
    
        return ans2;
    }
};