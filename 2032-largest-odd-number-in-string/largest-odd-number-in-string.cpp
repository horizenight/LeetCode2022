class Solution {
public:
    string largestOddNumber(string num) {
        //first odd digit from last index will give us its 
        int i  = num.length()-1;
         if (num[i] % 2 == 1) return num;
        int index = -1;
        while(i>=0){
            int  n = num[i];
            if(n%2 == 1) return num.substr(0, i + 1);
            i--;
        }
        return "";
    }
};