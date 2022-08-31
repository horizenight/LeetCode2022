class Solution {
public:
    bool isValid(string s) {
       
        
        
        stack<char>st ;
        if(s.length()== 0){
            return false;
        }
        
        for(int i = 0 ; i < s.length() ; i++){
            
            char ch = s[i];
            
            //if opening bracket , stack push 
//             if closing brakcet , check stacktop check and pop 
            
            if( ch=='(' || ch=='{' || ch == '['){
                st.push(ch);
            }else{
               
                if(!st.empty()){
                    char top = st.top();
                    if(
                        (ch == ')' && top == '(') ||
                         (ch == '}' && top == '{') ||
                         (ch == ']' && top == '[') ){
                        st.pop();
                        
                    }
                    else{
                        return false;
                    }
                }else{
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