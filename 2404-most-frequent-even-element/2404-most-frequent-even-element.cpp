class Solution {
    private:
    static bool cmp(pair<int,int> &a , pair<int,int> &b){
        return a.second > b.second ;
    }
public:
    int mostFrequentEven(vector<int>& nums) {
        
        map<int,int> m ;
        for(auto i : nums){
            m[i]++;
        }

        // have to sort map 
        vector<pair<int,int>> v ;
        for(auto it : m){
            v.push_back(it);
        }

sort(v.begin(),v.end(),cmp);

// now we have sorted values 

int ans = -1 ; int max =-1; 
for(auto it: v){
    if(it.first %2 == 0 && it.second > max){
        ans = it.first;
        max = it.second;
    }
}
// this gives us couter for max 
for(auto it:v){
    if(it.first %2 ==0 && it.second == max && it.first < ans){
        ans = it.first;
    }
}


return ans;
    }
};