class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> k(numRows);

        if(numRows == 1){
            return s;
        }
        bool flag = false;
        int i =0;
     

        for(auto ch : s){

            k[i] += ch;
            if(i == 0 || i==numRows - 1){
                flag = !flag;

            }
            if(flag){
                i++;
            }else{
                i--;
            }
        }

string ans="";
for(auto str : k){
    ans += str;
}
        
return ans;
    }
};