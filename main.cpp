#include <iostream>
#include <vector>

using namespace std;

// Given a list of non-overlapping intervals sorted by their start time.
// insert a given interval at the correct position and merge all mecessary
// intervals to produce a list of that has only mutually exclusive intervals.
// Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
// Output: [[1,3], [4,7], [8,12]]
// Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them
// into one [4,7]

class Interval {
public:
  int start;
  int end;
  Interval(int x, int y) : start(x), end(y) {}
};

// Note: for newInterval we pass the object as value not reference, since it is mod to find non-overlaping
//       interval
vector<Interval> insertInterval(const vector<Interval> intervals, Interval newInterval) {
  vector<Interval> mergedIntervals;
  int i = 0;

  // Note: find the first occurance of interval that is overlapped with new interval
  while(i < intervals.size() && intervals[i].end < newInterval.start) {
    mergedIntervals.push_back(intervals[i++]);
  }

  // mod newInterval its start and end include all intervals that are overlapped with newInterval
  while(i < intervals.size() && intervals[i].start <= newInterval.end) {
    newInterval.start = min(intervals[i].start, newInterval.start);
    newInterval.end = max(intervals[i].end, newInterval.end);
    i++;
  }
  // merge the newInterval
  mergedIntervals.push_back(newInterval);

  // add the remaining intervals.
  while (i < intervals.size()) {
    mergedIntervals.push_back(intervals[i++]);
  }
  
  return mergedIntervals;
}


int main() {
  std::cout << "Hello World!\n";
  vector<Interval> inputs = {{1, 3}, {5, 7}, {8, 12}};
  Interval insert = {4,6};
  auto result = insertInterval(inputs, insert);
  for (auto interval: inputs)
    cout<<interval.start<< "-"<<interval.end<<endl;
  return 0;
}