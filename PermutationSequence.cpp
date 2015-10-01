class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> nums;
        int sum = 1;
        string res;
        for(int i = 1; i <= n; ++i) {
            nums.push_back(i + '0');
        }
        k--; //真实索引
        //求n的阶乘
        for(int i = 1; i <= n; ++i) {
            sum *= i;
        }
        for(int i = 0; i < n; ++i) {
            sum = sum / (n - i);
            int index =  k / sum;
            k = k % sum;
            res.push_back(nums[index]);
            nums.erase(nums.begin() + index);
        }
        return res;
    }
    
};
