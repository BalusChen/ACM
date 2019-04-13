#include <stdio.h>
#include <vector>
#include <utility>

class Solution {
    public:
        bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
            int  idx, count = 0;
            std::vector<int>  degrees(numCourses, 0);
            std::vector<bool>  visited(numCourses, false);

            // every course has no prerequisite
            if (prerequisites.empty()) {
                return true;
            }

            for (auto &p : prerequisites) {
                if (degrees[p.second]++ == 0) {
                    count++;
                }
            }

#if NDEBUG
            for (int i = 0; i < degrees.size(); i++) {
                printf("counrse-%d: %d\n", i, degrees[i]);
            }
#endif

            while ((idx = findNewVertexOfIndegreeZero(degrees, visited)) < degrees.size()) {
                for (auto &p : prerequisites) {
                    if (p.first == idx) {
                        degrees[p.second]--;
                    }
                }
                if (--count == 0) {
                    return true;
                }
            }

            return false;
        }

        int findNewVertexOfIndegreeZero(const std::vector<int> &degrees, std::vector<bool> &visited) {
            int  i;

            for (i = 0; i < degrees.size(); i++) {
                if (!visited[i] && degrees[i] == 0) {
                    visited[i] = true;
                    break;
                }
            }

            printf("find course: %d\n", i);
            return i;
        }
};

int
main(int argc, char **argv)
{
    int  count;
    std::vector<std::pair<int, int>>  prerequisites;
    Solution  solution;
    bool  can;

    prerequisites = {
        { 1, 0 },
        { 0, 1 }
    };

    prerequisites = {
        { 0, 2 },
        { 1, 2 },
        { 2, 0 }
    };


    count = 3;

    can = solution.canFinish(count, prerequisites);
    printf("can: %d\n", can);
}
