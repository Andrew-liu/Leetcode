// 最蠢的方法: 返回的最小的时候, 遍历栈
// 第二蠢方法: 维护一个最小值
// 聪明的方法: 在维护一个最小栈数据结构, 彼此找到比当前小的元素都入此栈, 出栈判断是否为栈顶元素, 是的话也出栈
class MinStack {
public:
    void push(int x) {
        if(s_.empty()) {
            min_ = x;
        }
        if(x < min_) {
            min_ = x;
        }
        s_.push(x);
    }

    void pop() {
        int top = s_.top();
        if(min_ == top) {
            s_.pop();
            min_ = findSecondMin(s_);
        } else {
            s_.pop();
        }
    }
    int findSecondMin(stack<int> s) {
        int min = INT_MAX;
        int top = 0;
        while(!s.empty()) {
            top = s.top();
            if(min > top) {
                min = top;
            }
            s.pop();
        }
        return min;
    }
    int top() {
        return s_.top();
    }

    int getMin() {
        return min_;
    }
private:
    stack<int> s_;
    int min_;
};
