#include <stdio.h>
#include <vector>


struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};


void print_intervals(const std::vector<Interval> &);


std::vector<Interval>
merge(std::vector<Interval> &intervals)
{
    std::vector<Interval> ret;
    Interval v;
    int i;

    if (intervals.size() <= 1) return intervals;

    std::sort(intervals.begin(), intervals.end(), [](const Interval &v1, const Interval &v2) ->bool{return v1.start < v2.start;});
    // print_intervals(intervals);

    v = intervals[0];
    for (i = 1; i < intervals.size(); i++) {
        if (v.end >= intervals[i].start) {
            if (v.end < intervals[i].end) // 没有覆盖
                v.end = intervals[i].end;
        } else {
            ret.push_back(v);
            v = intervals[i];
        }
    }

#if 0
    if (v.end >= intervals[i-1].start) {
        if (v.end < intervals[i-1].end)
            v.end = intervals[i-1].end;
    } else {
        v = intervals[i];
    }
#endif 

    ret.push_back(v);

    return ret;
}

void
print_intervals(const std::vector<Interval> &intervals)
{
    for (auto &v : intervals) {
        printf("(s:%d, e:%d)  ", v.start, v.end);
    }

    printf("\n");
}


int
main(int argc, char **argv)
{
    std::vector<Interval> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    intervals = {
        {1, 4}, {2, 3}
    };

    intervals = {
        {1, 5}, {3, 7}
    };

    intervals = {
        {1, 3}
    };

    auto ret = merge(intervals);
    print_intervals(ret);
    exit(0);
}
