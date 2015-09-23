class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //思路: 第一种双重循环遍历, 时间复杂度为O(n^2), 所以想别的方法, 
        // 第二种, 两次循环, 第一次循环, 计算i元素所以之前元素的乘积, 第二次循环, 计算i元素所以之后的乘积
        int len = nums.size();
        vector<int> res(len, 1); //len长度的vector所有元素初始化为1
        for(int i = 0; i < len - 1; ++i) {
            res[i + 1] = res[i] * nums[i]; //由于第一个元素没有之前的元素, 所以不用计算, 从第二个元素起: 1, 1*2, 1*2*3
        }
        int tail = 1; //缓存后面元素的乘积
        for(int i = len - 1; i >= 1; --i) {
            tail *= nums[i];  //tail取值, 4, 4*3,  4*3*2
            res[i - 1] *= tail;  //由于最后一个元素没有之后的元素, 所以不用计算, 从倒数第二个元素: 1*2*4, 1*3*4, 2*3*4
        }
        return res;
    }
};
