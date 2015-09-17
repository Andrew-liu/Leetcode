class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;  //此处rowIndex从0开始, 为了方便使用, 我们直接从1开始
        vector<int> res;
        if (rowIndex < 1) {
            return res;
        }
        res.push_back(1);
        if (rowIndex == 1)  {
            return res;
        }
        for(int i = 2; i <= rowIndex; ++i) { //cong
            int temp = 1;
            for(int j = 1; j < i -1; j++) { //j = 0的位置必然为1, 不需要重新计算
                int prev = res[j];
                res[j] += temp;
                temp = prev;
            }
            res.push_back(1);
        }
        return res;
    }
};
