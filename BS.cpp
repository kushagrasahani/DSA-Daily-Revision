Q1 - Maximum Candies Allocated to K Children
Similar to book allocation problem
pattern is to find a possible range where your answer , since we needed the maximum every time when the
number of students >= required students, we incremented the low to find the maximum answer
else decrement the high

 long long findans(const vector<int>& nums, long long x) {
        long long s = 0;
        for (int v : nums)
            s += (v / x);
        return s;
    }

    int maximumCandies(vector<int>& nums, long long k) {
        long long sum = 0;
        long long maxi = 0;
        for (int v : nums) {
            sum += v;
            maxi = max(maxi, (long long)v);
        }

        if (sum < k)
            return 0;

        long long l = 1, h = maxi;
        long long ans = 0;

        while (l <= h) {
            long long mid = (l + h) / 2;
            long long res = findans(nums, mid);

            if (res >= k) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }
