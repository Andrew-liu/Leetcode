#include <string>
class Solution {
public:
    int lengthOfLastWord(std::string s) {
        if (s.length() == 0 || (s.length() == 1 && s[0] == ' ')) {
            return 0;
        }
        int len = s.length() - 1;
        while(s[len] == ' ' && len >= 0) {  //找到最后一个字符的位置
            len--;
        }
        int last_word_len = 0;
        while(s[len] != ' ' && len >= 0) {
            ++last_word_len;
            len--;
        }
        return last_word_len;
    }
};
