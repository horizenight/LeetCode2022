class Solution {
public:
    int arr[26] = {0};
    bool isAnagram(string s, string t) {
         if(s.size() != t.size()) return false;

        for(int it:s){
            arr[ it - 'a']++;
        }

          for(int it:t){
            arr[ it - 'a']--;
        }

        for(int it:arr){
            if(it!= 0) return false;
        }
        

          return true;
    }
};