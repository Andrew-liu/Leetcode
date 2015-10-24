//利用了缓存和排序的思想
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > buf;  //缓存每个排序过的字节
        sort(strs.begin(), strs.end());  //使生成的vector为字典序
        vector<vector<string> > res;
        int len = strs.size();
        for(int i = 0; i < len; ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());  //对每个字符串排序, 使它们变为相同的字符串用于hash
            unordered_map<string, vector<string> >::iterator iter = buf.find(s);
            if(iter == buf.end()) {
                vector<string> once;
                once.push_back(strs[i]);  //不能使用s, 因为s已经经过排序
                buf.insert(make_pair(s, once));
            } else {  //说明已经存在
                (iter->second).push_back(strs[i]);
            }
        }
        for(auto it = buf.begin(); it != buf.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};
