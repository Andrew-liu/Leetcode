#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res;
        int len = s.size();
        s.push_back(s[len - 1]);
        for (int i = 0; i < len; i++) {
            if(char2int(s[i]) >= char2int(s[i + 1])) { // 从最高位开始
                res += char2int(s[i]);
            } else {
                res -= char2int(s[i]);
            }
        }
        return res;
    }
    int char2int(char c) {
        switch(c) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return 0;
        }
    }
};

class Solution {
public:
    int romanToInt(string s) {
        int map[26];
        map['I'-'A'] = 1; 
        map['V'-'A'] = 5; 
        map['X'-'A'] = 10; 
        map['L'-'A'] = 50; 
        map['C'-'A'] = 100; 
        map['D'-'A'] = 500; 
        map['M'-'A'] = 1000;
        int res = 0, n = s.size();
        s.push_back(s[n-1]);
        for(int i = 0; i < n; i++)
        {
            if(map[s[i]-'A'] >= map[s[i+1]-'A']) {
                res += map[s[i]-'A'];
            } else {
                res -= map[s[i]-'A'];
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.romanToInt("DCXXI") << endl;
}