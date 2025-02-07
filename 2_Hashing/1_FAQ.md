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
Optimal:
```

```

```