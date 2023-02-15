class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string b = to_string(k);
        int alen = num.size();
        int blen = b.length();
        int carry = 0;
        int i = 0;

        string result = "";

        while( i < alen || i < blen || carry != 0){
            int x = 0;
            if( i < alen ){
                x = num[alen-1-i];
            }
          int y = 0;
            if(i < blen){
                y =(b[blen-1-i]-'0');

            }
           
            result = to_string((x+y+carry)%10) + result;
            carry =  ( x+y+carry ) /10;

          
            i++;


        }
        
     

        vector<int>wow;
        for(int i  = 0 ; i < result.size() ;i++){
            wow.push_back(result[i]-'0');
        }

        return wow;
    }
};