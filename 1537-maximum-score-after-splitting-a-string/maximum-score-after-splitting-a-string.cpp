class Solution {
public:
    int maxScore(std::string s) {
        int Max = 0;
        for (int i = 1; i < s.length(); ++i) {
            int maxx = std::count(s.begin(), s.begin() + i, '0') + std::count(s.begin() + i, s.end(), '1');
            Max = std::max(Max, maxx);
        }
        return Max;
    }
};