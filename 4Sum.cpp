// 类似与3 Sum, 也要保证元素不重复, 非降序
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int> > res;
        if(nums.size() < 4) {  // 小于4个元素时 无法找到为空的元素
            return vector<vector<int> >();
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; ++i) {
            for(int j = i + 1; j < nums.size() - 2; ++j) {
                int third = j + 1, fourth = nums.size() - 1;
                while(third < fourth) {
                    int sum = nums[i] + nums[j] + nums[third] + nums[fourth];
                    if(sum == target) {
                        vector<int> once;
                        once.push_back(nums[i]);
                        once.push_back(nums[j]);
                        once.push_back(nums[third]);
                        once.push_back(nums[fourth]);
                        res.insert(once);
                        ++third; 
                        --fourth;
                    } else if(sum < target) {
                        ++third;
                    } else {
                        --fourth;
                    }
                }
            }
        }
        return vector<vector<int> >(res.begin(), res.end());
    }
};
