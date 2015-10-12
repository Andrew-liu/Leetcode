// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        flag_ = false; 
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(!flag_) { //没有缓存值时
            value_ = Iterator::next();
            flag_ =true;
        }
        return value_;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if(!flag_) {  //无缓存值
            return Iterator::next();
        }
        return value_;
    }

    bool hasNext() const {
        if(flag_) {   //有缓存的下一位的值
            return true;
        }
        if(Iterator::hasNext()) { //没有缓存, 但是有下一位的值
            return true;
        }
    }
private:
    int value_; //缓存下一位的值
    bool flag_; //标记是否保存了下一位的值
};
