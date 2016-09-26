// 思路: 采用纵向计较的方法, 当字符串长度超过第一行或者字符不相等时, 返回公共的前缀即可
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int len = strs.size();
        if (len <= 0) {
            return res;
        }
        for(int i = 0; i < strs[0].size(); ++i) {  //以第一个字符串为比较基准, 与其他各字符串的每一位比较
            for(int j = 0; j < len; j++) {
                if(strs[j].size() == i || strs[j][i] != strs[0][i]) {  //如果比较的字符串大小等于, 当前比较的字符不相等时, 返回
                    return res;
                }
            } //当前位上的字符都相等
            res.push_back(strs[0][i]);
        }
        return res;
    }
};
