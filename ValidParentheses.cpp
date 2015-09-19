//思想: 使用栈进行括号匹配
class Solution {
public:
    bool isValid(string s) {
        stack<char> cache;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {  //如果是左括号则入栈
                cache.push(s[i]);
            }
            if(s[i] == ')') {
                if (!cache.empty() && ('(' == cache.top())) {  //判断通过则说明小括号匹配
                        cache.pop();
                        continue;
                } else {
                    return false;
                }
            }
            if(s[i] == ']') {
                if (!cache.empty() && ('[' == cache.top())) {  //判断成功则说明中括号匹配
                        cache.pop();
                        continue;
                } else {
                    return false;
                }
            }
            if(s[i] == '}') {
                if (!cache.empty() && ('{' == cache.top())) {
                        cache.pop();
                        continue;
                } else {
                    return false;
                }
            }
        }
        return cache.empty() ? true : false;
    }
};
