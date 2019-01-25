#include <vector>
#include <stdio.h>

class Solution {
    public:
        int searchInsert(std::vector<int> &nums, int target) {
            int left = 0, right = nums.size()-1, mid;

            while (left <= right) {
                mid = (left+right) / 2;
                // printf("left=%d\tmid=%d\tright=%d\n", left, mid, right);
                if (nums[mid] < target) {
                    left = mid+1;
                } else if (nums[mid] > target){
                    right = mid-1;
                } else {
                    return mid;
                }
            }

            return left;
        }
};
        int searchInsert(std::vector<int> &nums, int target) {
            int left = 0, right = nums.size()-1, mid;

            while (left <= right) {
                mid = (left+right) / 2;
                // printf("left=%d\tmid=%d\tright=%d\n", left, mid, right);
                if (nums[mid] < target) {
                    left = mid+1;
                } else if (nums[mid] > target){
                    right = mid-1;
                } else {
                    return mid;
                }
            }

            return left;
        }

int main(int argc, char **argv) {
    std::vector<int> ivec {1, 3, 5};

    printf("target = %d\tpos = %d\n", 5, searchInsert(ivec, 5));
    printf("target = %d\tpos = %d\n", 2, searchInsert(ivec, 2));
    printf("target = %d\tpos = %d\n", 7, searchInsert(ivec, 7));
    printf("target = %d\tpos = %d\n", 0, searchInsert(ivec, 0));
    printf("target = %d\tpos = %d\n", 3, searchInsert(ivec, 3));
}
