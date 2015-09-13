#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int str_len = s.size();
        int res;
        for(int i = 0; i < s.size(); ++i) {
            res += (s[i] - 'A' + 1) * pow(26, --str_len);
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.titleToNumber("A") << endl;
    return 0;
}
