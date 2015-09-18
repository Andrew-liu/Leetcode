#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int one_index = m - 1;
        int two_index = n - 1;
        int i;
        for(i = m + n - 1; i >= 0 && one_index >= 0 && two_index >= 0; --i) {
            if(nums1[one_index] >= nums2[two_index]) {
                nums1[i] = nums1[one_index--];  //先移动元素到对应的位置, 然后索引减一
            } else {
                nums1[i] = nums2[two_index--];
            }
        } 
        while (two_index >= 0) {  
            nums1[i] = nums2[two_index]; // i 和 two_index都要减一操作
            i--;
            two_index--;
        }
    }
};
int main(int argc, char** argv) {
    vector<int> num1(10, 0);
    num1[2] = 3;
    vector<int> num2;
    num2.push_back(-1);
    num2.push_back(1);
    num2.push_back(1);
    num2.push_back(1);
    num2.push_back(2);
    num2.push_back(3);
    Solution s;
    s.merge(num1, 3, num2, 6);
    for(auto num : num1) {
        cout << num << " ";
    }
}
