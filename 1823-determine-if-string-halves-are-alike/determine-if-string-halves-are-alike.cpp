class Solution {
public:
    bool checkVowel(char a){
        char arr[5]={'a','e','i','o','u'};
        bool flag = false;
        for(auto i : arr){
            if(i == tolower(a)){
                flag = true;
            }
        }

        return flag;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count1 = 0;
        int count2 =0;

        for(int i = 0 ; i < n/2 ;i++){
            if(checkVowel(s[i])) count1++;
        }

        for(int i = n/2 ; i <n ;i++){
             if(checkVowel(s[i])) count2++;
        }

        return count1 == count2;
    }
};