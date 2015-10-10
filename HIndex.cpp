/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool help(int a, int b) {
    return (a > b ? true : false);
}
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), help);
        int len = citations.size();
        for(int i = 0; i < len; ++i) {
            if(i >= citations[i]) {
                return i;
            }
        }
        return len;
    }
};
