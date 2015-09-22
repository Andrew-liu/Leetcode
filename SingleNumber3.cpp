// 超时了, 我感觉思路没错, 要优化一下
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 异或所有数, 得到两个唯一出现的异或结果, 其他的都相互抵消
        int len = nums.size(), xor_num = onlyNumber(nums), index = 0;
        // 从低位开始, 找到二进制表示的第一位为一的位
        while((xor_num & 1) == 0) {
            xor_num >> 1; //否则右移一位
            index++;
        } //此时找到为1的index, 然后对vector划分成两类
        vector<int> first, second;
        for(int i = 0; i < len; ++i) {
            if((nums[i] >> index) & 1 == 0) {
                first.push_back(nums[i]);
            } else {
                second.push_back(nums[i]);
            }
        }
        vector<int> res;
        res.push_back(onlyNumber(first));
        res.push_back(onlyNumber(second));
        return res;
    }
    int onlyNumber(vector<int>& nums) {
        int res = 0, len = nums.size();
        for(int i = 0; i < len; ++i) {
            res ^= nums[i];
        }
        return res;
    }
};

//优化: 直接在分类的同时求出两个分段异或值
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 异或所有数, 得到两个唯一出现的异或结果, 其他的都相互抵消
        int len = nums.size(), xor_num = onlyNumber(nums), index = 0;
        // 从低位开始, 找到二进制表示的第一位为一的位
        while((xor_num & 1) == 0) {
            xor_num >>= 1; //否则右移一位
            index++;
        } //此时找到为1的index, 然后对vector划分成两类
        int first = 0, second = 0;
        for(int i = 0; i < len; ++i) {
            if(((nums[i] >> index) & 1) == 0) {
                first ^= nums[i];
            } else {
                second ^= nums[i];
            }
        }
        vector<int> res;
        res.push_back(first);
        res.push_back(second);
        return res;
    }
    int onlyNumber(vector<int>& nums) {
        int res = 0, len = nums.size();
        for(int i = 0; i < len; ++i) {
            res ^= nums[i];
        }
        return res;
    }
};
