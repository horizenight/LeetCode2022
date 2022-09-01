class Solution {
private:
    
public:
    int minSwaps(string s) {
        
    stack <char>st ;
    for(int i = 0 ; i < s.length() ; i++){
        char ch = s[i];
        
        if(ch == '['){
            st.push(ch);
        }
        else{
//             ch is a closed brace 
            if(!st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
        
        if(st.empty()){
            return 0;
        }
        
//         now we have only case left where ]]]][[[
      int size = (st.size())/2;
        
        
      int  ans = (size-1)/2 + 1;
        
        
        return ans ;
    }
};