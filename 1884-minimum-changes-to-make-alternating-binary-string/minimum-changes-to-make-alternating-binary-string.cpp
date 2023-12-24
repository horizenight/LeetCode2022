class Solution {
public:
    pair<string,string> altString(int n){
        int index = 1;
        string s1="";
        string s2="";
        while(index <= n){
            s1+="01"; 
            s2+="10";
            index+=2;
        }
        return {s1,s2};
    }
    int minOperations(string s) {
        int n = s.size();
        pair<string,string> p = altString(n);
        int cost1 = 0 , cost2=0;
        for(int i = 0 ; i<s.size();i++){
            if(s[i] != p.first[i]) cost1++;
            if(s[i] != p.second[i]) cost2++;
        }

        return min(cost1,cost2);
    }
};