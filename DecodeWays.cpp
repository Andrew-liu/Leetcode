class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) {
            return 0;
        }
        int len = s.size();
        vector<int> dp(len + 2, 1);
        for(int i = 2; i < len + 2; ++i) {
            if(s[i - 2] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i - 1];
            }
            if(i - 3 >= 0 && (s[i - 3] == '1' || s[i - 3] == '2' && s[i - 2] <= '6')) {
                dp[i] += dp[i -2];
            }
        }
        return dp[len + 1];
    }
};
