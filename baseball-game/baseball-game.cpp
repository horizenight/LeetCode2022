class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string>st;
        for(string it : operations){
            
                if(it == "C"){
                    st.pop();
                }
                else if(it == "D"){
                   int num1 = stoi(st.top()); 
                   st.push(to_string( num1 * 2));
                }
                else if(it =="+"){
                    int num1 = stoi(st.top()); st.pop();
                    // cout<<num1;
                    int num2 = stoi(st.top());
                    st.push(to_string(num1));

                    st.push(to_string(num1+num2));
                }else{
                    st.push(it);
                }
           
        }


        int sum = 0;
        while(!st.empty()){
            cout<<st.top()<<" ";
            sum += stoi(st.top()); st.pop();
        }

        return sum;
    }
};