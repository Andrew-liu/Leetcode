#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dict[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if(digits.size() == 0) {
            return res;
        }
        string once(digits.size(), '0');
        helper(digits, 0, dict, once, res);
        return res;
    }
    void helper(const string& digits, int index, string* dict, string& once, vector<string>& res) {
        if(index == digits.size()) {
            res.push_back(once);
            return;
        }
        string value = dict[digits[index] - '0'];
        cout << value << endl;
        for(int i = 0; i < value.size(); ++i) {
            once[index] = value[i];
            helper(digits, index + 1, dict, once, res);
        }
    }
};

int main(int argc, char** argv) {
    string test("23");
    Solution s;
    vector<string> res = s.letterCombinations(test);
    for(auto str : res) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
