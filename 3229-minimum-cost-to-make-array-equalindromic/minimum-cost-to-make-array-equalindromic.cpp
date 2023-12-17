class Solution {
public:
    bool isPalindrome(int x){
        string s = to_string(x);
        int i =0 , j = s.size()-1;
        while(i <= j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int inc(int x){
        while(!isPalindrome(x)){
            x++;
        }
        return x;
    }
    int dec(int x){
        while(!isPalindrome(x)){
            x--;
        }
        return x;
    }
    long long val(int a ,vector<int>&nums){
        long long ans =0;
        for(auto i : nums){
            ans += abs(a-i);
        }
        return ans;
    }
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int a = inc(nums[n/2]);
        int b = dec(nums[n/2]);

        // logic : find closes palindrom to median and then  calculate cost 
        return min(val(a,nums),val(b,nums));
    }
};