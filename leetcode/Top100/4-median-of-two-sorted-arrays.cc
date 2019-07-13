
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
                    all[k] = nums1[i];
                    i++;

                } else {
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

#if 0
            for (auto c : all) {
                std::cout << c << "  ";
            }
            std::cout << std::endl;
#endif

            return median;
        }
};


class Solution2 {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            int         start, end;
            int         partition_1, partition_2, max_l_1, min_r_1, max_l_2, min_r_2;
            double      median;

            if (nums1.size() > nums2.size()) {
                return findMedianSortedArrays(nums2, nums1);
            }

            start = 0;
            end = nums1.size();
            while (start <= end) {
                partition_1 = (start + end) / 2;
                partition_2 = (nums1.size() + nums2.size() + 1) / 2 - partition_1;

                max_l_1 = partition_1 == 0 ? INT32_MIN : nums1[partition_1 - 1];
                min_r_1 = partition_1 == nums1.size() ? INT32_MAX : nums1[partition_1];
                max_l_2 = partition_2 == 0 ? INT32_MIN : nums2[partition_2 - 1];
                min_r_2 = partition_2 == nums2.size() ? INT32_MAX : nums2[partition_2];

                if (max_l_1 <= min_r_2 && max_l_2 <= min_r_1) {

                    if ((nums1.size() + nums2.size()) % 2 == 1) {
                        median = std::max(max_l_1, max_l_2);

                    } else {
                        median = (std::max(max_l_1, max_l_2) + std::min(min_r_1, min_r_2)) / 2.0;
                    }

                    break;

                } else if (max_l_1 > min_r_2) {
                    end = partition_1 - 1;

                } else {
                    start = partition_1 + 1;

                }
            }

            return median;
        }
};


int
main(int argc, char **argv)
{
    Solution2           ans;
    std::vector<int>    nums1, nums2;

    nums1 = { 1, 3, 9, 17, 21 };
    nums2 = { 2, 5, 7, 19, 23, 25, 27 };
    printf("median: %f\n", ans.findMedianSortedArrays(nums1, nums2));


    nums1 = { 1, 2, 3, 4, 5 };
    nums2 = { 6, 7, 8, 9, 10 };
    printf("median: %f\n", ans.findMedianSortedArrays(nums1, nums2));

    nums1 = { 7, 9, 13 };
    nums2 = { 1, 2 };
    printf("median: %f\n", ans.findMedianSortedArrays(nums1, nums2));

    nums1 = {  };
    nums2 = { 1, 3, 5, 7, 9 };
    printf("median: %f\n", ans.findMedianSortedArrays(nums1, nums2));

    nums1 = {  };
    nums2 = { 1, 2, 3, 4 };
    printf("median: %f\n", ans.findMedianSortedArrays(nums1, nums2));

    nums1 = { 1, 3 };
    nums2 = { 2 };
    printf("median: %f\n", ans.findMedianSortedArrays(nums1, nums2));

    return 0;
}
