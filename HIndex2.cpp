// 数组是升序排列, 要找index, 使用二分查找, 然后使用元素值与序号比较
class Solution { 
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size(), beg = 0, end = len - 1;
        int mid = 0;
        while(beg <= end) {
            mid = beg + (end - beg) / 2;
            if(citations[mid] == len - mid) {
                return len - mid;
            } else if (citations[mid] > len - mid){ 
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return len - beg;
    }
};
