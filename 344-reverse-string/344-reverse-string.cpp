class Solution {
public:
    void reverseString(vector<char>& s) {
        
//      stack<char>st;
//     vector<char>ans;
        
        
//         for(int i = 0 ; i < s.size();i++){
//             char ch = s[i];
//             st.push(ch);
//         }
        
//         while(!st.empty()){
//             char ch = st.top();
//             ans.push_back(ch);
//             st.pop();
//         }
        
//         s = ans;
        
        int i = 0 ;
        int j = s.size()-1;
        
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
    }
};