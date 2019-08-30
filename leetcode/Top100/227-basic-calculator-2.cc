
/*
 * Copyright (C) Jianyong Chen
 */


#include <string>


class Solution {
private:
    enum tok_type_e {
        tok_plus,
        tok_minus,
        tok_multi,
        tok_divid,
        tok_number,
        tok_eof,
    };

    struct tok_t {
        tok_type_e  type;
        int         number;

        tok_t() = default;
        tok_t(tok_type_e t) : type(t) {  }
        tok_t(tok_type_e t, int n) : type(t), number(n) {  }
    };

    int          cur_pos;
    tok_t        cur_token;
    std::string  text;

    int expr() {
        int         results;
        tok_type_e  type;

        results = term();
        while (cur_token.type == tok_plus || cur_token.type == tok_minus) {
            type = cur_token.type;

            if (type == tok_plus) {
                consume(tok_plus);
                results += term();

            } else {
                consume(tok_minus);
                results -= term();
            }
        }

        return results;
    }

    int term() {
        int         results;
        tok_type_e  type;

        results = factor();
        while (cur_token.type == tok_multi || cur_token.type == tok_divid) {
            type = cur_token.type;

            if (type == tok_multi) {
                consume(tok_multi);
                results *= factor();

            } else {
                consume(tok_divid);
                results /= factor();
            }
        }

        return results;
    }

    int factor() {
        tok_t  token = cur_token;
        consume(tok_number);
        return token.number;
    }

    void consume(tok_type_e type) {
        assert(type == cur_token.type);
        cur_token = get_next_token();
    }

    tok_t get_next_token() {
        long  number;

        while (cur_pos < text.size()) {


            switch (text[cur_pos]) {
            case ' ':
                skip_whitespace();
                break;

            case '+':
                cur_pos++;
                return tok_t(tok_plus);

            case '-':
                cur_pos++;
                return tok_t(tok_minus);

            case '*':
                cur_pos++;
                return tok_t(tok_multi);

            case '/':
                cur_pos++;
                return tok_t(tok_divid);

            default:    /* number */
                number = 0;
                while (cur_pos < text.size() && isnumber(text[cur_pos])) {
                    number = number * 10 + text[cur_pos] - '0';
                    cur_pos++;
                }
                return tok_t(tok_number, number);
            }
        }

        return tok_t(tok_eof);
    }

    void skip_whitespace() {
        while (cur_pos < text.size() && std::isspace(text[cur_pos])) {
            cur_pos++;
        }
    }

public:
    int calculate(std::string s) {
        text = s;
        cur_pos = 0;
        cur_token = get_next_token();

        return expr();
    }
};


int
main(int argc, char **argv)
{
    Solution     ans;
    std::string  s;

    s = "3+2*2";
    printf("%s: %d\n", s.c_str(), ans.calculate(s));

    s = " 3/2 ";
    printf("%s: %d\n", s.c_str(), ans.calculate(s));

    s = " 3+5 / 2 ";
    printf("%s: %d\n", s.c_str(), ans.calculate(s));

    s = "2147483647";
    printf("%s: %d\n", s.c_str(), ans.calculate(s));

    return 0;
}
