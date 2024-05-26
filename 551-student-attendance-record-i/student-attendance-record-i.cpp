class Solution {
public:
    bool checkRecord(string s) {
        int absen = count(s.begin(),s.end(),'A');
        int late = s.find("LLL");
        return absen<2 and late ==-1;
    }
};