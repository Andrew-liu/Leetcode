#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int indicator = 1;
        for(int i = 0; i<str.size();) {
            i = str.find_first_not_of(' ');
            //符号判断
            if(str[i] == '-' || str[i] == '+')
                indicator = (str[i++] == '-') ? -1 : 1;
            while('0'<= str[i] && str[i] <= '9') {
                result = result*10 + (str[i++]-'0');
                //溢出情况
                if(result * indicator >= INT_MAX) {
                    return INT_MAX;
                }
                if(result*indicator <= INT_MIN) { 
                    return INT_MIN;
                }
            }
            return result*indicator;
        }
    }
};

// 注意空格, 正负号和溢出
class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int size = str.size();
        int symbol = 1;
        
        for(int i = 0; i < size;) {
            while(str[i] == ' ') {
                i++;
            }
            if(str[i] == '-' || str[i] == '+') {
                symbol = str[i] =='-' ? -1 : 1;
                i++;
            }
            while(i < size && isdigit(str[i])) {
                res = res * 10 + (str[i++] - '0');
                if(res * symbol >= INT_MAX) {
                    return INT_MAX;
                }
                if(res * symbol <= INT_MIN) {
                    return INT_MIN;
                }
            }
            return (int)symbol * res;
        }
        return (int)symbol * res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.myAtoi("2147483648") << endl;
}
