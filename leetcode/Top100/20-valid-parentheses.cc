
/*
 * Copyright (C) Jianyong Chen
 */


#include <string>
#include <stack>


class Solution {
    public:

        bool isLeft(char ch) {
            return ch == '(' || ch == '[' || ch == '{';
        }

        char theOther(char ch) {
            switch (ch) {
                case ')':
                    return '(';
                case ']':
                    return '[';
                case '}':
                    return '{';
                default:
                    return '.';     // never reach here.
            }
        }

        bool isValid(std::string s) {
            int                 i;
            char                right;
            std::stack<char>    stk;

            if (s.empty()) {
                return true;
            }

            for (i = 0; i < s.size(); i++) {

                if (isLeft(s[i])) {
                    stk.push(s[i]);

                } else {
                    if (stk.empty()) {
                        return false;
                    }

                    right = theOther(s[i]);
                    if (stk.top() != right) {
                        return false;
                    }

                    stk.pop();
                }
            }

            if (!stk.empty()) {
                return false;
            }

            return true;
        }
};

