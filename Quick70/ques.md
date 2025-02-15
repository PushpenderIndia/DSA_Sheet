## Big O Complexity
Big O time complexities in order from lowest to highest, along with examples:  

| **Big O Notation** | **Complexity Name**       | **Example**                                             |
|--------------------|--------------------------|---------------------------------------------------------|
| **O(1)**          | Constant Time            | Accessing an element in an array (`arr[0]`)            |
| **O(log n)**      | Logarithmic Time         | Binary search (`O(log n)`)                             |
| **O(n)**          | Linear Time              | Looping through an array (`for i in range(n)`)        |
| **O(n log n)**    | Linearithmic Time        | Merge Sort, QuickSort (average case)                   |
| **O(n²)**         | Quadratic Time           | Nested loops (Bubble Sort, Selection Sort)             |
| **O(n³)**         | Cubic Time               | Triple nested loops                                    |
| **O(2ⁿ)**         | Exponential Time         | Recursive Fibonacci (`fib(n) = fib(n-1) + fib(n-2)`)   |
| **O(n!)**         | Factorial Time           | Traveling Salesman Problem (brute force approach)      |

## Table of Content
- [Array](#array)
    - [Contains Duplicate](#1-contains-duplicate)
    - [Missing Number](#2-missing-number)
    - [Find all missing numbers](#3-find-all-missing-numbers)
    - [Two Sum](#4-two-sum)

## Array
### 1. Contains Duplicate: 
[Leetcode Link](https://leetcode.com/problems/contains-duplicate/description/)
```
Problem: Check list for duplicates
```

```
Solution Intuition: 

O(N): Using Hashmap for frequency, single loop for updating freq & checking freq count
O(1): Using Set, If contains duplicate, then length of Original array != Set array
```

- O(N) - Using Hashmap
```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> freq;
        for (int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
            if (freq[nums[i]] > 1){
                return true;
            }
        }   
        return false;
    }
};
```

- O(1) - Using set
```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> setnums(nums.begin(), nums.end());
        if (setnums.size() != nums.size()){
            return true;
        } else {
            return false;
        }
    }
};
```

### 2. Missing Number
[Leetcode Link](https://leetcode.com/problems/missing-number/description/)

```
Problem: Check list for one missing number in range [0,n]
```

```
Solution Intuition: 

O(NlogN): Sort Array and then Check Current element with current Index in for loop
O(N): 
```

- O(NlogN)

```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i<=nums.size(); i++){
            if (i == nums.size()){
                return i;
            }
            else if (nums[i] != i){
                return i;
            }
        }
        return -1;
    }
};
```

- O(N)

```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumOfN = 0;
        int sumOfArray = 0;
        for (int i=0; i<nums.size(); i++){
            sumOfN += i+1;
            sumOfArray += nums[i];
        }
        return sumOfN - sumOfArray;
    }
};
```

### 3. Find All Missing Numbers
[Leetcode Link](https://leetcode.com/problems/missing-number/description/)
```
Problem: Check given list for missing numbers range(1, len(nums))
```

- O(N): unordered_set find func complexity O(1) & Single for loop O(N)

```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missing;
        unordered_set<int> st(nums.begin(), nums.end());

        int n = nums.size();
        for (int i=1; i<=n; i++){
            if (st.find(i) == st.end()){
                missing.push_back(i);
            }
        }
        return missing;
    }
};
```

### 4. Two Sum
[Leetcode Link](https://leetcode.com/problems/two-sum/)
```
Problem: Return index of two nums whose sum is equal to target
```

```
O(N): Calc difference b/w target & current num, if that is present in unordered_map, return its indices
```

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        for (int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if (hm.find(diff) != hm.end()){
                return {i, hm[diff]};
            }
            hm[nums[i]] = i; 
        }
        return {-1, -1};
    }
};
```

### 5. How many numbes are smaller than ?
[Leetcode Link](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/)
```
Problem: 
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
```

```
Solution:
```

- T: O(2N) & S: O(3N)

```
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int> hm;
        vector<int> ans;
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        for (int i=0; i<temp.size(); i++){
            if (hm.find(temp[i]) == hm.end()){
                hm[temp[i]] = i;
            } 
        }

        for (auto it : nums){
            ans.push_back(hm[it]);
        }
        return ans;
    }
};
```

### 6. Minimum Time Visiting All Points
```
Problem:
```

```
Solution Intuition:

Calc Chebyshev distance: 
time = max(|x2 - x1|, |y2- y1|)
```

- O(N)
```
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total_time = 0;
        for (int i=1; i<points.size(); i++){
            int diff1 = abs(points[i][0] - points[i-1][0]);
            int diff2 = abs(points[i][1] - points[i-1][1]);
            total_time += max(diff1, diff2);
        }
        return total_time;
    }
};
```