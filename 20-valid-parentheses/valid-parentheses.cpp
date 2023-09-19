class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0){
            return false;
        }
        // using stack 
        stack<int> st;
        for(char ch : s){
            
            if(ch=='(' || ch=='{' || ch =='['){
                // its a open bracket 
                st.push(ch);
            } 
            else{
                if(!st.empty()){
                   int t = st.top();
                   if( t == '[' && ch == ']' ){
                       st.pop();
                   }
                   else if( t == '{' && ch == '}' ){
                       st.pop();
                   }else if( t == '(' && ch == ')' ){
                       st.pop();
                   }
                   else{
                        return false;
                   }
                }
                 else{
            return false;
        }
            }
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};