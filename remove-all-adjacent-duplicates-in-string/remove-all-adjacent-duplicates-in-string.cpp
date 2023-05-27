class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i = 0 ; i <s.length();i++){
            char ch =s[i];

            if(st.empty()){
                st.push(ch);
            }
            else{
                if(st.top() == ch){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }

        }

        // now stack will contain only the required string but if we pop we will get reverse
        string ans ="";
        while(!st.empty()){
            char top_elem = st.top();
            cout<<top_elem;
            ans = top_elem+ans;
            st.pop();
        }

        return ans;
        
    }
};