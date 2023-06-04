class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        if(s.length() == 0) {
            return false;
        }

        for(int i = 0 ; i < s.length() ;i++){
            char ch = s[i];

            if(ch == '[' || ch == '{' || ch =='('){
                st.push(ch);
            }else{
                if(!st.empty()){
                char charTop = st.top();
                    
                if(ch ==']' && charTop == '['){
                    st.pop();
                }
                else if(ch =='}' && charTop == '{'){
                    st.pop();
                }
                  else if(ch ==')' && charTop == '('){
                    st.pop();
                }
                else {
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

        return false;
        
    }
};