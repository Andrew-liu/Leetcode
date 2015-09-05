class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {  // only positive sum
            return false;
        }
        if (num == 1) { // num is equal to 1
            return true;
        }
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num %5 == 0) {
            num /= 5;
        }
        return (num == 1);
    }
};
