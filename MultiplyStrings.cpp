//题意: 将两个字符串表示的数字, 做乘法后返回字符串, 并且数字是任意大的!

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int k = n1 + n2 - 2, carry = 0;
        vector<int> v(n1 + n2, 0);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i < n1 + n2; ++i) {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
    }
        int i = n1 + n2 - 1;
        while (v[i] == 0) --i;
        if (i < 0) {
            return "0";
        }
        while (i >= 0) { //将数字的每一位拼接回去
            res.push_back(v[i--] + '0');
        }
        return res;
    }
};
