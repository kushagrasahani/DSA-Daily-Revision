// Pattern - Merging intervals
// Steps -
// 1 sort the intervals by start time and take an resultant vector (ans)
// 2 initially take variables intialised to the 0th interval
// 3 loop from1 - n , find the merging condiotn , if overlapping then pop from ans , construc the new interval , 
// point your s1, e1 to the new interval , then push back in ans, if not overlapping then point s1,e1 to current interval
// and push in ans

// handle if any edge cases are pending where the intervals might get skipped

// Questions - 1. Merging intervals , Tc - O(nlogn)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int m = intervals[0].size();
        int s1 = intervals[0][0];
        int e1 = intervals[0][1];
        ans.push_back({s1,e1});
        for(int i=1; i<n;i++){
           
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            if(e1 >= s2){
                ans.pop_back();
                int fs1 = min(s1,s2);
                int fs2 = max(e1,e2);
                s1 = fs1;
                e1 = fs2;
                ans.push_back({fs1,fs2});
            }
            else {
                s1 = s2;
                e1 = e2;
                ans.push_back({s1,e1});
            }
        }
        return ans;
    }
};


// 2. Insert interval , Tc - O(n)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int s2 = newInterval[0];
        int e2 = newInterval[1];
        int i;
        for (i = 0; i < n; i++) {
            int s1 = intervals[i][0];
            int e1 = intervals[i][1];
            if (e1 < s2) {
                ans.push_back({s1, e1});
            } else
                break;
        }
        if (i == n || e2 < intervals[i][0])
            ans.push_back({s2, e2});
        else {
            int s1 = intervals[i][0];
            int e1 = intervals[i][1];
            int fs1 = min(s1, s2);
            int fs2 = max(e1, e2);
            ans.push_back({fs1, fs2});
            s1 = fs1;
            e1 = fs2;
            i++;
            while (i < n) {
                s2 = intervals[i][0];
                e2 = intervals[i][1];
                if (e1 >= s2) {
                    ans.pop_back();
                    s1 = min(s1, s2);
                    e1 = max(e1, e2);
                    ans.push_back({s1, e1});
                } else {
                    s1 = s2;
                    e1 = e2;
                    ans.push_back({s1, e1});
                }
                i++;
            }
        }
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};