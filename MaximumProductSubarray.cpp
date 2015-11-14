class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int imin, imax, res, len = nums.size();
        if(len <= 0) {
             return 0;
        }
        res = imax = imin = nums[0];
        for(int i = 1; i < len; ++i) {
            int temp = imax;
            imax = max(max(imax * nums[i], imin * nums[i]), nums[i]);
            imin = min(min(temp * nums[i], imin * nums[i]), nums[i]);
            res = max(res, imax);
        }
        return res;
    }
};
