class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int size = input.size();
        for(int i = 0; i < size; ++i) {
            char cur = input[i];
            if(cur == '+' || cur == '-' || cur == '*') {
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
                for(auto n1 : result1) {
                    for(auto n2 : result2) {
                        if(cur == '+') 
                            res.push_back(n1 + n2);
                        else if(cur == '-') 
                            res.push_back(n1 - n2);
                        else{
                            res.push_back(n1 * n2);
                        }
                    }
                }
            }
        }
        if(res.empty()) { //输入字符串只包含数字的情况
            res.push_back(atoi(input.c_str()));
        }
        return res;
    }
};
