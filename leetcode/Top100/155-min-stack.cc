#include <stack>
#include <iostream>


class MinStack1 {
    public:
        /** initialize your data structure here. */
        MinStack1() {
            size_     = 0;
            capacity_ = 16; // initial capacity
            data_     = new int[capacity_];
        }

        ~MinStack1() {
            delete[] data_; // ATTENTION: use `delete[]` rather than delete
            size_ = capacity_ = 0;
        }

        void push(int x) {
            if (size_ == capacity_) {
                reallocate_data();
            }

            data_[size_++] = x;

            if (supporting_stk_.empty() || x <= supporting_stk_.top()) {
                supporting_stk_.push(x);
            }
        }

        void pop() {
            assert(size_ != 0);

            if (data_[--size_] == supporting_stk_.top()) {
                supporting_stk_.pop();
            }
        }

        int top() {
            assert(size_ != 0);

            return data_[size_-1];
        }

        int getMin() {
            assert(size_ != 0);

            return supporting_stk_.top();
        }

    private:
        void  reallocate_data() {
            int  *new_data;

            capacity_ += (capacity_ >> 1);  // 1.5 times larger
            new_data = new int[capacity_];

            // move original elements
            for (int i = 0; i < size_; i++) {
                new_data[i] = data_[i];
            }

            delete[] data_;
            data_ = new_data;
        }

        int  *data_;
        int   size_;
        int   capacity_;

        std::stack<int>  supporting_stk_;
};

class MinStack2 {
    public:
        /** initialize your data structure here. */
        MinStack2() = default;

        void push(int x) {
            main_stk_.push(x);
            if (min_stk_.empty() || x <= min_stk_.top()) {
                min_stk_.push(x);
            }
        }

        void pop() {
            assert(!main_stk_.empty());
            if (main_stk_.top() == min_stk_.top()) {
                min_stk_.pop();
            }

            main_stk_.pop();
        }

        int top() {
            assert(!main_stk_.empty());

            return main_stk_.top();
        }

        int getMin() {
            assert(!min_stk_.empty());

            return min_stk_.top();
        }

    private:
        std::stack<int>  main_stk_;
        std::stack<int>  min_stk_;
};


class MinStack {
    public:
        MinStack() {
            min_ = INT_MAX;
        }

        void push(int x) {
            if (x <= min_) {
                stk_.push(min_);
                min_ = x;
            }

            stk_.push(x);
        }

        void pop() {
            if (stk_.top() == min_) {
                stk_.pop();
                min_ = stk_.top();
            }

            stk_.pop();
        }

        int top() {
            return stk_.top();
        }

        int getMin() {
            return min_;
        }

    private:
        std::stack<int>  stk_;
        int  min_;
};

int
main(int argc, char **argv)
{
    MinStack *stk = new MinStack();

    stk->push(0);
    stk->push(1);
    stk->push(0);

    std::cout << stk->getMin() << std::endl;

    stk->pop();
    std::cout << stk->getMin() << std::endl;

    return 0;
};
