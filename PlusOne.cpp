class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> new_digits(digits.size(), 0);  //存放新的数
        int plus = 1;
        for(int i = digits.size() - 1; i >= 0; --i) {
            plus += digits[i];  //当前为加一
            new_digits[i] = plus % 10; //防止plus超过十, 超过十产生了进位
            plus /= 10; //确定前一位是否需要加上进位, 如果plus小于 10, 则不产生进位, plus = 0
        }
        if(new_digits[0] == 0) {  //防止最高位溢出
            new_digits.insert(new_digits.begin(), plus);
        }
        return new_digits;
    }
};
