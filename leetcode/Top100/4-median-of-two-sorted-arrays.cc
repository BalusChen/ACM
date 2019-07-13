
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <iostream>


class Solution {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            int                 i, j, k;
            double              median;
            std::vector<int>    all(nums1.size()+nums2.size());

            for (i = 0, j = 0, k = 0; i < nums1.size() && j < nums2.size(); k++) {
                if (nums1[i] < nums2[j]) {
                    printf("get from nums1\n");
                    all[k] = nums1[i];
                    i++;

                } else {
                    printf("get from nums2\n");
                    all[k] = nums2[j];
                    j++;
                }
            }

            for (/* void */; i < nums1.size(); i++, k++) {
                all[k] = nums1[i];
            }

            for (/* void */; j < nums2.size(); j++, k++) {
                all[k] = nums2[j];
            }

            if (all.size() % 2 == 1) {  /* odd */
                median = all[(all.size()-1) / 2];

            } else {
                median = (all[(all.size()-1) / 2] + all[all.size() / 2]) / 2.0;
            }


#if 1
            for (auto c : all) {
                std::cout << c << "  ";
            }
            std::cout << std::endl;
#endif

            return median;
        }
};
