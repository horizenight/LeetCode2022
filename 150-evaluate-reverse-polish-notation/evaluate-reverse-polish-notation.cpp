class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() ==1 ){
            return stoi(tokens[0]);
        }
        stack<string> st;
        for(int i = 0 ; i<tokens.size() ; i++){
            string num = tokens[i];
            if(num == "+" || num =="-"|| num=="*" || num =="/"){
                st.push(num);
                string oper = num;
                st.pop();

                int num1 = stoi(st.top()); st.pop();
                int num2 = stoi(st.top()); st.pop();
                cout<<num1 <<" "<<num2 <<endl;
                int ans;
                if(oper == "+"){
                    ans = num1 + num2;
                }
                if(oper == "-"){
                    ans = num2 - num1;
                }
                if(oper == "*"){
                    ans = num1 * num2;
                }
                if(oper == "/"){
                    ans = num2/ num1;
                }
                // cout<<ans<<endl;
                st.push(to_string(ans));
               
            }else{

            st.push(num);
            }
        }
   
        return stoi(st.top());
    }
};