
//  Q- COMBINATION SUM II
//  Pattern - Using For loop to evaluate multiple choices to pick/not pick at each index
//  firstly you sort the array so as to give sorted arrays as resultant subsequence
//  Since every index can be used as a start index so you loop in the array for each index of the resultant sequence
//  No two same elements can be used as the start index , so if after the current index you find a same element
//  you skip it making sure there are no two duplicates in the array
//  Tc - O(2^n) * k + nlogn
//  SC- O(k) + O(N) + O(2^n);
 void findans(vector<int>& candidates, int ind, int target, vector<int>& res,
                 vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        if (ind >= candidates.size())
            return;
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            res.push_back(candidates[i]);
            findans(candidates, i + 1, target - candidates[i], res, ans);
            res.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // your code goes here
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        vector<vector<int>> ans;
        findans(candidates, 0, target, res, ans);
        return ans;
    }