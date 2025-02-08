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

```
Bruteforce
```

```
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            int current_sum = 0;
            int ele_count = 0;
            for (int j=i+1; j<nums.size(); j++){
                current_sum += nums[j];
                ele_count++;
                if (current_sum == k){
                    ans = max(ans, ele_count);
                } else if (current_sum > k){
                    break;
                }
            }
        }
        return ans;
    }
};
```

```
Optimal (for Positive & Negative numbers)
```

```
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            if (sum == k){
                maxLen = max(maxLen, i+1);
            }

            int rem = sum - k;
            if (preSumMap.find(rem) !=  preSumMap.end()){
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            if (preSumMap.find(sum) == preSumMap.end()){
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};
```

```
Optimal: For Positive nums only
```

```
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();        
        int maxLen = 0;
        int left = 0, right = 0;
        int sum = nums[0];

        while(right < n) {
            while(left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }
            
            if(sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }
            
            right++;
            if(right < n) sum += nums[right];
        }
        
        return maxLen;
    }
};
```

### 3. Count subarrays with given sum
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

```
Bruteforce
```

```
class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            int current_sum = 0;
            for (int j=i; j<nums.size(); j++){
                current_sum += nums[j];
                if (current_sum == k){
                    ans++;
                }
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