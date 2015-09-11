/*
 * 如果字符串s可以通过字符替换的方式得到字符串t，则称s和t是同构的
 * 通过这句可以得到对应关系
 * s_dict[t[i]] = s[i]
 * t_dict[s[i]] = t[i] 如果不满足条件则不是同构的
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_dict, t_dict;
        for (int i = 0; i < s.size(); ++i) {
            unordered_map<char, char>::iterator s_iter = s_dict.find(t[i]);
            unordered_map<char, char>::iterator t_iter = t_dict.find(s[i]);
            if(s_iter == s_dict.end() && t_iter == t_dict.end()) {
                //相互映射关系放入对应的hash map中
                s_dict[t[i]] = s[i];
                t_dict[s[i]] = t[i];
            } else if (s_dict[t[i]] != s[i] || t_dict[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
