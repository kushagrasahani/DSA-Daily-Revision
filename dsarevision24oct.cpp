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
