class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i = 0; i < n; i++) {  //使用镜面排序生成格雷码
            int height_bit = 1 << i;
            int len = res.size();
            for(int j = len - 1; j >= 0; --j) { // i = 1, 次数产生第2个格雷码, i = 2, 此处产生第3, 4个格雷码, i = 3, 产生5, 6, 7下标的格雷码
                res.push_back(height_bit | res[j]);
            }
        }
        return res;
    }
};
