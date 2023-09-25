 #include <bits/stdc++.h>
 using namespace std;

 vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(begin(intervals), end(intervals));
    int end = 0;
    for(auto interval : intervals) {
        if(interval[0] <= intervals[end][1])                          
           intervals[end][1] = max(intervals[end][1], interval[1]);
        else                                              
            intervals[++end] = interval;
    }
    intervals.resize(end+1);
    return intervals;
}

int main() {
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    merge(arr);

    for(auto i:arr) {
        for(auto j:i) {
            cout << j << ", ";
        } cout << endl;
    }
}