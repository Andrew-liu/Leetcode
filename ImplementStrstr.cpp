// 土逼方法: 逐位比较, 不相等则比较的后移. 更优秀的想法KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() == 0 && needle.size() == 0) {
            return 0;
        }
        int first_len = haystack.size();
        int second_len = needle.size();
        for(int i = 0; i < first_len - second_len + 1; ++i) { //注意这里的长度应该是两个字符串的长度的差再+1
            int j, loc = i;
            for(j = 0; j < second_len; ++j) {
                if(haystack[loc] != needle[j]){
                    break;
                } else {
                    loc++;
                }
            }
            if(j >= second_len) {
                return i;
            }
        }
        return -1;
    }
};
