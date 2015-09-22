class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> temp(32, 0);
        int res = 0;
        int len = nums.size(); 
        for (int i = 0; i < len; ++i) {
            for(int j = 0; j < 32; j++) { //取出每一位, 并累加到对应的temp位上
                int move_num = nums[i] >> j;
                if(move_num ==  0) { // 此时说明有效位的移位已经完成
                    break;
                }
                temp[j] += move_num & 1; //取得当前最低位
            }
        }
        for(int i = 0; i < 32; ++i) {
            res += ((temp[i] % 3) << i); //由于temp中元素分散, 需要移位重组
        }
        return res;
    }
};
