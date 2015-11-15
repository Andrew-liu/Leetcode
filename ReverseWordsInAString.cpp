//思路: 先每个单词进行翻转, 然后再进行整体翻转
class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j = 0, k = 0, word_len = 0;
        while(true) {
            while(i < s.size() && s[i] == ' ') {
                ++i;  //开头为空格的时候过滤掉
            }
            if(i == s.size()){
                break;
            }
            if(word_len) {
                s[j++] = ' ';
            }
            k = j;
            while(i < s.size() && s[i] != ' ') {
                s[j] = s[i];
                ++j;
                ++i;
            }
            reverseWord(s, k, j - 1);
            ++word_len;
        }
        s.resize(j);
        reverseWord(s, 0, j - 1);
    }
    void reverseWord(string& s, int i, int j) {
        while(i < j) {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }
};
