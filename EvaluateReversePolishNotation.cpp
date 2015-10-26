/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
//借助stack实现, 后缀式
//借助stack实现, 后缀式
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> buf;
        for(int i = 0; i < tokens.size(); ++i) {
            if(tokens[i].size() > 1 || (tokens[i][0] >= '0' && tokens[i][0] <= '9')) {
                buf.push(atoi(tokens[i].c_str()));
                continue;
            }
            int first = buf.top();
            buf.pop();
            int second = buf.top();
            buf.pop();
            if(tokens[i] == "+") {
                buf.push(second + first);  //注意这里要反过来写, 栈是后进先出
            } else if(tokens[i] == "-") {
                buf.push(second - first);
            } else if(tokens[i] == "*") {
                buf.push(second * first);
            } else if(tokens[i] == "/") {
                buf.push(second / first);  
            }
        }
        return buf.top();
    }
};

int main(int argc, const char *argv[]) {
    vector<string> test;
    test.push_back("0");
    test.push_back("3");
    test.push_back("/");
    Solution s;
    std::cout << s.evalRPN(test) << std::endl;
    return 0;
}
