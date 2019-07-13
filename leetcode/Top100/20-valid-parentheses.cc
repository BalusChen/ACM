
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

        char leftPart(char ch) {
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

            if (s.size() % 2 == 1) {
                return false;   // odd-length string won't be balanced
            }

            for (i = 0; i < s.size(); i++) {

                if (isLeft(s[i])) {
                    stk.push(s[i]);

                } else {
                    if (stk.empty()) {
                        return false;
                    }

                    if (stk.top() != leftPart(s[i])) {
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

