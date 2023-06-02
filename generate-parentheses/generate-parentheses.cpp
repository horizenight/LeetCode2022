class Solution {

    bool validParenthesis(string &a ){
        stack<char> st;
        for(int i = 0 ; i < a.size() ; i++){
            char ch = a[i];

            if(ch == '('){
                st.push(ch);
            }else{
                if(st.empty()){
                    return false;
                }else{
                    if(st.top() == '('){
                        st.pop();
                    }
                }
            }
        }

        if(st.empty()){
            return true;
        }

        return false;
    }

void printPermutations(vector<string> &allString,string str)
{
    // Sort the string in lexicographically increasing order
    sort(str.begin(), str.end());
 
 
    // Keep printing the next permutation until there is no next permutation
    do {
       allString.push_back(str);
    } while (next_permutation(str.begin(), str.end()));
}
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allString ; 
        string a = "";
        for(int i = 0 ; i<n;i++){
            a += '(';
         
        }
        for(int i = 0 ; i<n;i++){
            a += ')';
         
        }
        // cout<<a <<endl;
        printPermutations(allString,a);
        // now we have a vector that contains all the string combination that we require 

        vector<string>ans;
        for(auto b : allString){
            // cout<< b << " "<< validParenthesis(b);
            if(validParenthesis(b)){
                ans.push_back(b);
            }
            // cout<< b <<"-";
        }
        return ans;
    }
};