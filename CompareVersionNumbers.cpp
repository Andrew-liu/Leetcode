// 思路: 对字符串转换成两个整数处理, 
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int first = 0, second = 0;
        int first_len = version1.size(), second_len = version2.size();
        for(int i = 0, j =0; i < first_len || j < version2.size(); ++i, ++j) {
            first = 0;
            while(i < first_len && version1[i] != '.') {
                first = first * 10 + (version1[i++] - '0'); //转换成整数
            }
            second = 0;
            while(j < second_len && version2[j] != '.') {
                second = second * 10 + (version2[j++] - '0'); //转换成整数
            }
            if (first > second) {
                return 1;
            } else if (first < second) {
                return -1;
            }
        }
        return 0;
    }
};
