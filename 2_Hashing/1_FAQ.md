### 1. Longest Consecutive Sequence in an Array
Given an array nums of n integers, return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

```
Better: T [ O(NlogN) + O(N) ] S: O(1)
```

```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        int current_max = 1;
        sort(nums.begin(), nums.end());

        for (int i=1; i<nums.size(); i++){
            if (nums[i] == nums[i-1] + 1){
                current_max++;
                ans = max(current_max, ans);
            } 
            
            else if (nums[i] != nums[i - 1]) {
                current_max = 1;
            }
        }
        return ans;
    }
};
```

```
Optimal: T: [ O (2xN) ] S: [O(N)]

Unordered set find time complexity is O(1) in avg case (uses hash table)
O(N) for worst case
```

```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        int current_max = 1;
        unordered_set<int> st(nums.begin(), nums.end());

        for (auto it : st){
            if (st.find(it - 1) == st.end()){
                current_max = 1;
                int start_ele = it;
                while (st.find(start_ele + 1) != st.end()){
                    start_ele += 1;
                    current_max += 1;
                }
                ans = max(current_max, ans);
            }
        }
        return ans;
    }
};
```

### 2. Longest subarray with sum K
Given an array nums of size n and an integer k, find the length of the longest sub-array that sums up to k. If no such sub-array exists, return 0.

