// Hash-Based Sequence Expansion
// Usage-
// ->trying to find the length of a contiguous range (or sequence) based on an implicit rule 
// (e.g., consecutive integers, consecutive letters, consecutive timestamps)?
// ->Can I identify the “starting point” of such a sequence via a local property 
// (like x-1 not being present)?
// -> Can I check “next element exists?” in O(1) time via hashing?
// Basically if u have to find a consecutive range without distorting th array then this approach helps
// Here we assumed that if the current element is the starting point of the sequence , then iterate to find all the
// elements of that sequence thereby incrementing the length, its better to iterate in set only as this reduces
// the number of operations performed
// TOTAL time complexity - O(n) + O(2n);
// Space - O(n);

int longestConsecutive(vector<int>& nums) {
       int maxi = 0;
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        //iterate in set
        for(auto it:st){
            int x = it;
            if(st.find(x-1) == st.end()){
                int len = 1;
                while(st.find(x+1) != st.end()){
                    len++;
                    x++;
                }
                maxi = max(maxi, len);
            }
        }
        // for (int i = 0; i < nums.size(); i++) {
        //     int len = 0;
        //     int req = nums[i] - 1;
        //     if(st.find(req) == st.end()){
        //         req = req + 1;
        //         while(st.find(req) != st.end()){
        //             len++;
        //             req++;
        //         }
        //     }
        //     maxi = max(maxi, len);
        // }
        return maxi;
    }