class Solution {
    private:
    static bool cmp(pair<char,int> &a , pair<char,int>&b){
        return a.second > b.second ;
    }
public:
    string frequencySort(string s) {
        // hasmap to create count of char and their value add to empty string accordin
        map<char,int> m ; 
        for(auto it : s ){
            m[it]++;
        }
        vector<pair<char,int>> v;

        for(auto it: m){
           v.push_back(it);
        }

sort(v.begin(),v.end(),cmp);



    string ans = "";
    for(auto it: v){
        for(int i = 0 ; i < it.second ; i++){
            ans += it.first;
        }
    }

 
        return ans;
    }
};