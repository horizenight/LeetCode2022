
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;

        // int index = s.find_last_not_of(' ');
        // cout<<index; cannot as get TLE 

        int flag = 0;
        for(int i = n-1 ; i>=0;i--){
            
            if(s[i]!=' '){
                flag = 1;
                count++;
            }
            else if(flag==1){
                break;
            }
        }
      return count ;
    }

};