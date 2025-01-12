### 1. Leaders in an Array
Given an integer array nums, return a list of all the leaders in the array.

A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

```
Bruteforce
```

```
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;

        for (int i=0; i<nums.size(); i++){
            bool currentLeader = true;
            for (int j=i; j<nums.size(); j++){
                if (nums[i] < nums[j]){
                    currentLeader = false;
                    break;
                }
            }

            if (currentLeader){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
```

```
Optimal
```

```

```