

#include <string>


class Solution {
    public:
        void replaceSpace(char *str,int length) {
            int          i, j;
            std::string  ret(str);

            for (i = 0, j = 0; i < ret.size(); i++) {
                if (isspace(ret[i])) {
                    str[j] = '%';
                    str[j+1] = '2';
                    str[j+2] = '0';

                    j += 3;
                } else {
                    str[j] = ret[i];
                    j++;
                }
            }
            str[j] = '\0';
        }
};
