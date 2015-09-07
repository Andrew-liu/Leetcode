#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) { //同字母异序词
        if(s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        cout << s << endl;
        cout << t << endl;
        if (s == t) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    s.isAnagram("hello", "oelhe");
    return 0;
}

