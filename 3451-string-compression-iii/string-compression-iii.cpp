class Solution {
public:
    string compressedString(string word) {
      string comp = "";
      int count =1;
       for(int i = 0 ; i<word.size() ; i++){
            if(word[i] == word[i+1] && count != 9){
                // equal 
                count++;
            }
            else if(count == 9){
                comp+= to_string(count);
                count=1;
                comp+=word[i];
            }
            else if(word[i] != word[i+1] && count != 9){
                comp+= to_string(count);
                count=1;
                comp+=word[i];
            }
        
       } 

       return comp;
    }
};