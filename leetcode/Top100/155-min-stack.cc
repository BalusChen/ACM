#include <stack>
#include <iostream>


class MinStack {
    public:
        /** initialize your data structure here. */
        MinStack() {
            size_     = 0;
            capacity_ = 16; // initial capacity
            data_     = new int[capacity_];
        }

        ~MinStack() {
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
