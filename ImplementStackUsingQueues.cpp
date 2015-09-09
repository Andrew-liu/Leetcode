/*
 * 思路: 使用双队列, 维护q1作为插入元素, pop时, 将q1的元素留一下, 剩下的全部插入到q2, pop后, 再将所有元素放回q1
 */

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q1_.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(q1_.size() > 1) {
            int temp = q1_.front();
            q1_.pop();
            q2_.push(temp);
        }
        q1_.pop();
        while(!q2_.empty()) {
            int temp = q2_.front();
            q2_.pop();
            q1_.push(temp);
        }
    }

    // Get the top element.
    int top() {
        while(q1_.size() > 1) {
            int temp = q1_.front();
            q1_.pop();
            q2_.push(temp);
        }
        int top = q1_.front();
        q1_.pop();
        q2_.push(top);
        while(!q2_.empty()) {
            int temp = q2_.front();
            q2_.pop();
            q1_.push(temp);
        }
        return top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (q1_.empty() ? true : false);
    }
private:
    queue<int> q1_;
    queue<int> q2_;
};
