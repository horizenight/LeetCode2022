class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
         unordered_set<string> cities;
        for(auto &it:paths){
            string a = it[0];
            cities.insert(a);
        }

        for(auto it: paths){
            string b = it[1];
            if(cities.find(b) == cities.end()){
                return b;
            }
        }

    return "";
    }
};