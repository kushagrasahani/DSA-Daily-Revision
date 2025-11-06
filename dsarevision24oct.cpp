//  Pattern - 2 pointers
//  used when we need to find a pair that satifies a target or whenever we need to remove duplicates as a pair

//  Q1 - Remove Duplicates from Sorted Array
 int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] == nums[k]) {
                i++;
            } else {
                k++;
                nums[k] = nums[i];
                i++;
            }
        }
        return k + 1;
    }

    // Q2 - Remove Element - imp to understand pattern
     int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 1) {
            if (nums[0] == val)
                return 0;
            return 1;
        }
        int k = 0;
        int i = 0;
        while (i<nums.size()) {
           if(nums[i]!= val){
            nums[k] = nums[i];
            i++;
            k++;
           }
            else {
                i++;
            }
        }
        return k;

    }



  // Q3 - container with most water
  // bs dekh area = w * h , ab width to dec kr hi rhi hai , to l inc krni padegi
  // to isiliye jb bhi choti length ho to uss direction ka pointer inc kro

     int maxArea(vector<int>& height) {
        int maxi = 0;
        int i=0;
        int j = height.size()-1;
        while(i < j){
            int h = min(height[i], height[j]);
            int w = j-i;
            maxi = max(maxi , h*w);
            if(height[i] < height[j]){
                i++;
            }
            else j--;
        }
        return maxi;
    }

// Q4 - Longest Mountain in Array
// first analyse that there could be multiple peaks so binary search is not a valid option here, Peaks can be in the range [1,n-2] , loop in this range
// and find all the possible peaks, at each finding , find the range of the valley , s=i -> 1 & i=i-> n-2 , then i++;
// keep count = 1 for each peak and as you keep finding the valley , inc count;

// PATTERN - Expanding the range based on possible answers

int longestMountain(vector<int>& arr) {
        int i = 1;
        int j = arr.size() - 2;
        int ans = 0;
        while (i <= j) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int count = 1;
                int s = i;
                while (s > 0 && arr[s] > arr[s - 1]) {
                    s--;
                    count++;
                }
                while (i < arr.size() - 1 && arr[i] > arr[i + 1]) {
                    count++;
                    i++;
                }
                ans = max(ans, count);
                i++;
            } else
                i++;
        }
        return ans;
}

// PATTERN - PREFIX SUFFIX PATTERN
// If each element’s final contribution depends on both what came before and what comes after,
//  you can almost always apply prefix–suffix accumulation.
//  maintain a pref and suff = 1
//  for i=0-N
//  pref = pref*nums[i];
//  suff = suff*nums[n-i-1];
//  if(pref == 0 || suff == 0)pref = 1;suff = 1;
//  maxi = max(maxi, max(pref, suff));
//  return maxi
//  //MY CODE
//  keep multiplying if not 0
//  if prod < 0
//  r = i+1
//  find the produc after this until u find a 0
//  if the newprod < 0 , maxi = prod * new prod
//  else maxi = newprod
//  if newpord == 0 break
//  i= r;
//  prod = 1 // resst it to find the prod after the 0
//  same idea , just not keeping oref and suff
 int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int maxi = INT_MIN;
        int prod = 1;
        int zeroc = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroc++;
                maxi = max(maxi, 0);
                prod = 1; // reset
                continue;
            }
            prod *= nums[i];
            maxi = max(maxi, prod);
            if (prod < 0) {
                int r = i + 1;
                int newprod = 1;
                while (r < n) {

                    if (nums[r] == 0){
                        zeroc++;
                     break; // break chain at zero
                    }
                        
                    newprod *= nums[r];
                    if (newprod < 0) { // found another negative
                        maxi = max(maxi, prod * newprod);
                    } else
                        maxi = max(maxi, newprod);
                    r++;
                }
                i = r; // skip processed segment
                prod = 1;
            }
        }
        if(maxi < 0 && zeroc > 0)return 0;
        return maxi;
    }



