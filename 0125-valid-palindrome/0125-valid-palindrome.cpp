class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(auto it : s ){
            if(iswalnum(it)) {
                ans+= tolower(it);
            }
        }

// now to check palindrome 


    // using stack or reverse the string 
    string f_ans = "";
    for(int i = ans.length()-1 ; i >= 0 ;i--){
        f_ans += ans[i];
    }
    cout<< f_ans << endl;
    cout<<ans;

    if(f_ans == ans){
        return true;
    }

        return false;
    }
};