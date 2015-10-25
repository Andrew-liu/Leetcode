//容易想的是暴力解法, 我想肯定会超时的, 复杂度为O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                if(nums[i] + nums[j] == target) {  //解是唯一的
                    res.push_back(i + 1);
                    res.push_back(j + 1);
                    break;
                }
            }
        }
        return res;
    }
};

// 第一次遍历数组使用哈希表哈希元素及对应的下标
// 在一次遍历数组, 每次求出剩余的数, 然后在哈希表中查找是否已经存在, 且值和当前值是不相等的
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> buf;
        for(int i = 0; i < nums.size(); ++i) {
            buf[nums[i]] = i;  
        }
        for(int i = 0; i < nums.size(); ++i) {
            int temp = target - nums[i];
            if(buf.find(temp) != buf.end() && buf[temp] != i) {
                res.push_back(i + 1);
                res.push_back(buf[temp] + 1);
                break; //题目告诉我们解是唯一的
            }
        }
        return res;
    }
};
