class Solution {
public:
    string removeKdigits(string num, int k) {
         

         int n = num.size();
         stack<char> st;

         for(char c : num){

             while(!st.empty() && k >0 && st.top() > c){
                 st.pop(); k-=1;
             }
            if(!st.empty() || c != '0'){
                st.push(c);
            }
         }

        //  now stack will have only increasing element and may happen k value is not 0 
        while(!st.empty() && k--){
         st.pop();   
        }
        if(st.empty()){
            return "0";
        }

        // now stak contains the desired 
      
        while(!st.empty()){
            num[n-1] = st.top();
           st.pop();
           n-=1;
        }

        return num.substr(n);
    }
};