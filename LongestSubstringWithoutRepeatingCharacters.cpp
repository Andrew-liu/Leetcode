//查找给定字符串的不重复字符子串的最大长度
//使用一个字符数组来记录所有字符, 当没有重复数组时, 不断更新res, 每次最后更新对应字符的值为index + 1, 表示出现重复后, left应该开始的地方
//出现重复数组, 则应该找到上次保存的字符的值(其中存储着不重复元素的开始位置)
// 最后返回res即为最大
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ascii[256] = {0}, res = 0, left = 0;  //left一直记录不重复的左边的起始位置
        int len = s.size();
        if(len == 0) {
            return res;
        }
        for(int i = 0; i < s.size(); ++i) {
            if(ascii[s[i]] == 0 || ascii[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {  // 此时出现重复的
                left = ascii[s[i]];  
            }
            ascii[s[i]] = i + 1; // 更新当前字符对应的值 + 1, 因为序号从零开始
        }
        return res;
    }
};
