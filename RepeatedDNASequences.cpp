//题意: 给定一个DNA字符串序列, 找到其中出现长度为10 且一只一次的序列 >= 2
//思路: 看网上是利用的ACGT四个ASCII的特点, 分别为 0100 0001  0100 0011  0100 0111   0101 0100
//后三位是不同的, 则通过一个32位的int可以存储10个字母的后三位(需要30位), 存储哈希表, 并设定出现频率
//然后没移动一个字母, 就在哈希表查找一下
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() < 10) {
            return res;  //小于10的字符串, 没有符合要求的序列
        }
        unordered_map<int, int> m;
        int i = 0, ten_str = 0, mask = 0x7ffffff; //0x7ffffff, 后27位全一, 可以得到后27位, 然后右移三位, 
        while(i < 9) {  //第一次循环9个字符, 并构造32位的后三位组合
            ten_str = (ten_str << 3) | (s[i++] & 7);  //每个字符取后三位
        }
        for(; i < s.size(); ++i) {
            ten_str = ((ten_str & mask) << 3) | (s[i] & 7);//取后27位, 再或上新字符的最后30, 组成30位, 到map中查找
            if(m.find(ten_str) != m.end()) { //进入此判断说明至少会出现两次
                if(m[ten_str] == 1) {
                    res.push_back(s.substr(i - 9, 10)); 
                }
                m[ten_str]++;
            } else {
                m[ten_str] = 1; //第一次出现, 设置频率为1
            }
        }
        return res;
    }
};
