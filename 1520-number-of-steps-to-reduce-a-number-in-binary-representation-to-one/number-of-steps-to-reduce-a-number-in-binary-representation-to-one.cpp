class Solution {
public:
    int numSteps(string s) {
        // if even divide by 2
        // if even number is odd then you have to add 1 
        int count = 0;
        int l = s.length() -1;
        int carry =0;

        while(l>0){
            if(s[l]-'0'+carry == 0 ){
                carry = 0;
                count++;
            }
            else if(s[l] - '0' + carry == 2){
                carry =1;
                count++;
            }
            else{
                carry = 1;
                count+=2;
            }
            l--;
        }

        if(carry == 1){
            count++;
        }
    return count;
    }
};