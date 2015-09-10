class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_map<int, int> dict;
       for (int i = 0; i < nums.size(); ++i) {
           if(dict.find(nums[i]) != dict.end()) {
               return true;
           }
           dict[nums[i]] = i;
       }
       return false;
    }
};
