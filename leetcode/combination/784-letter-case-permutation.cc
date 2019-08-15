
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <string>
#include <iostream>


class Solution {
    public:

        std::vector<std::string> letterCasePermutation(std::string S) {
            std::vector<std::string>  results;

            if (S.empty()) {
                return results;
            }

            dfs(results, S, 0);

            return results;
        }

    private:

        void dfs(std::vector<std::string> &results, std::string &str,
                 int start)
        {
            int  i;

            results.push_back(str);

            for (i = start; i < str.size(); i++) {
                if (!isalpha(str[i])) {
                    continue;
                }

                convert(str[i]);
                dfs(results, str, i+1);
                convert(str[i]);
            }
        }

        void convert(char &ch) {
            if (std::isupper(ch)) {
                ch = std::tolower(ch);

            } else {
                ch = std::toupper(ch);
            }
        }
};


int
main(int argc, char **argv)
{
    Solution                  ans;
    std::string               str;
    std::vector<std::string>  results;

    str = "a1b2";
    results = ans.letterCasePermutation(str);
    for (const auto &s : results) {
        std::cout << s << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
