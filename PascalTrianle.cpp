kclass Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if(numRows < 1) {
            return res;
        }
        vector<int> row(1, 1);  //第一行直接入vector
        res.push_back(row);
        if(numRows == 1) {
            return res;
        }
        for(int i = 2; i <= numRows; ++i) {  //从第二行开始算
            int temp = 1;
            for(int j = 1; j < i - 1; ++j) {  //第0为1已经存在, 所以从indexj = 1开始
                int prev = row[j];
                row[j] += temp;  
                temp = prev;
            }
            row.push_back(1); //补上最后一位1
            res.push_back(row); //一行完成放入队列
        }
        return res;
    }
};
