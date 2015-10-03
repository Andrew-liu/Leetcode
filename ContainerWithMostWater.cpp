// ai表示构成容器的两个高度, x轴的差表示宽度, 计算容器容纳水的体积
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len == 0) {
            return 0;
        }
        int beg = 0, end = len - 1;
        int max_num = INT_MIN;
        while(beg < end) {  //水的体积取决于最小的高度
            int container = min(height[beg], height[end]) * (end - beg);
            max_num = max(container, max_num);
            if(height[beg] < height[end]) { //将高度较小的位置指针向中间移动
                beg++;
            } else {
                end--;
            }
        }
        return max_num;
    }
};
