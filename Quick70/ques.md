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
    - [How many numbers are smaller than](#5-how-many-numbes-are-smaller-than-)
    - [Time Minimum Visting all points](#6-minimum-time-visiting-all-points)
    - [Spiral Matrix](#7-spiral-matrix)
    - [Number of Islands](#8-number-of-islands)
- [Array Two Pointers](#arrays-two-pointers)
    - [Best Time to Buy and Sell Stock](#9-best-time-to-buy-and-sell-stock)
    - [Squares of a sorted array](#10-squares-of-a-sorted-array)
    - [3SUM](#11-3sum)
    - [Longest Mountain in array](#12-longest-mountain-in-array)
- [ARRAYS SLIDING WINDOW](#arrays-sliding-window)
    - [](#14-minimum-absolute-difference)
    - [](#15-minimum-size-subarray-sum)
    - [](#16-single-number)
    - [](#17-coin-change)

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

### 7. Spiral Matrix
[Leetcode link](https://leetcode.com/problems/spiral-matrix/description/)

```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (left <= right && top <=bottom){
            // left to right
            for (int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            // top to bottom
            for (int j=top; j<=bottom; j++){
                ans.push_back(matrix[j][right]);
            }
            right--;

            // right to left
            if (top <= bottom){
                for (int k=right; k>=left; k--){
                    ans.push_back(matrix[bottom][k]);
                }
                bottom--;
            }

            // bottom to top
            if (left <= right){
                for (int l=bottom; l>=top; l--){
                    ans.push_back(matrix[bottom][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
```

### 8. Number of Islands
[Leetcode link](https://leetcode.com/problems/number-of-islands/description/)

```
Problem:
```

```
Solution:
```

```
```

## ARRAYS TWO POINTERS
### 9. Best Time to Buy and Sell Stock
[Leetcode link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Set to a very high value initially
        int maxProfit = 0;      // No profit initially

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;  // Update lowest price
            } 
            else {
                maxProfit = max(maxProfit, price - minPrice);  // Check max profit
            }
        }
        return maxProfit;
    }
};
```

### 10. Squares of a Sorted Array
[Leetcode link](https://leetcode.com/problems/squares-of-a-sorted-array/description/)

```
Bruteforce: O(NlogN)
```

```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squared;
        for (int i=0; i<nums.size(); i++){
            squared.push_back(nums[i] * nums[i]);
        }
        sort(squared.begin(), squared.end());
        return squared;
    }
};
```

```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int pos = n - 1;
        int left = 0;
        int right = n - 1;
        while (left <= right){
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare){
                result[pos] = leftSquare;
                left++;
            } else {
                result[pos] = rightSquare;
                right--;
            }
            pos--;
        }
        return result;
    }
};
```

### 11. 3Sum
[Leetcode link](https://leetcode.com/problems/3sum/description/)

```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());  // Step 1: Sort the array

    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Avoid duplicates for i

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicate values
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } 
            else if (sum < 0) {
                left++;  // Increase sum
            } 
            else {
                right--; // Decrease sum
            }
        }
    }
    return result;
}
```

### 12. Longest Mountain in Array
[Leetcode link](https://leetcode.com/problems/longest-mountain-in-array/description/)

```
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; // A mountain must have at least 3 elements

        int longest = 0;
        for (int i = 1; i < n - 1; i++) { // Start from the second element
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) { // Check if it's a peak
                int left = i, right = i;

                // Move left pointer back while it's increasing
                while (left > 0 && arr[left] > arr[left - 1]) left--;

                // Move right pointer forward while it's decreasing
                while (right < n - 1 && arr[right] > arr[right + 1]) right++;

                // Update longest mountain length
                longest = max(longest, right - left + 1);
            }
        }
        return longest;
    }
};
```

## ARRAYS SLIDING WINDOW
### 13. Contains Duplicate II
[Leetcode link](https://leetcode.com/problems/contains-duplicate-ii/description/)

```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        for (int i=0; i<nums.size(); i++){
            if (hm.find(nums[i]) != hm.end()){
                int dist = i - hm[nums[i]];
                if (dist <= k){
                    return true;
                } 
            }
            hm[nums[i]] = i;

        }
        return false;
    }
};
```

### 14. Minimum Absolute Difference
[Leetcode link](https://leetcode.com/problems/minimum-absolute-difference/description/)

```
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int small_diff = INT_MAX;
        for (int i=1; i<arr.size(); i++){
            int diff = arr[i] - arr[i-1];
            small_diff = min(small_diff, diff);
        }

        for (int i=1; i<arr.size(); i++){
            int diff = arr[i] - arr[i-1];
            if (diff == small_diff){
                ans.push_back({arr[i-1], arr[i]});
            }
        } 
        return ans;
    }
};
```

### 15. Minimum Size Subarray Sum
[Leetcode link](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

```
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;
        for (int right=0; right<nums.size(); right++){
            sum += nums[right];

            while (sum >= target){
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
```

## BIT MANIPULATION
### 16. Single Number
[Leetcode link](https://leetcode.com/problems/single-number/description/)

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
```

## DYNAMIC PROGRAMMING
### 17. Coin Change
[Leetcode link](https://leetcode.com/problems/coin-change/description/)

```
```

### 18. Climbing Stairs
[Leetcode link](https://leetcode.com/problems/climbing-stairs/description/)

### 19. Maximum Subarray
[Leetcode link](https://leetcode.com/problems/maximum-subarray/description/)

### 20. Counting Bits
[Leetcode link](https://leetcode.com/problems/counting-bits/description/)

### 21. Range Sum Query - Immutable
[Leetcode link](https://leetcode.com/problems/range-sum-query-immutable/description/)

## BACKTRACKING
### 22. Letter Case Permutation
[Leetcode link](https://leetcode.com/problems/letter-case-permutation/description/)

### 23. Subsets
[Leetcode link](https://leetcode.com/problems/subsets/description/)

### 24. Combinations
[Leetcode link](https://leetcode.com/problems/combinations/description/)

### 25. Permutations
[Leetcode link](https://leetcode.com/problems/permutations/description/)

## LINKED LISTS
### 26. Middle of Linked List
[Leetcode link](https://leetcode.com/problems/middle-of-the-linked-list/description/)

### 27. Linked List Cycle
[Leetcode link](https://leetcode.com/problems/linked-list-cycle/description/)

### 28. Reverse Linked List
[Leetcode link](https://leetcode.com/problems/reverse-linked-list/description/)

### 29. Remove Linked List Elements
[Leetcode link](https://leetcode.com/problems/remove-linked-list-elements/description/)

### 30. Reverse Linked List II
[Leetcode link](https://leetcode.com/problems/reverse-linked-list-ii/description/)

### 31. Palindrome Linked List
[Leetcode link](https://leetcode.com/problems/palindrome-linked-list/description/)

### 32. Merge Two Sorted Lists
[Leetcode link](https://leetcode.com/problems/merge-two-sorted-lists/description/)

## STACKS
### 33. Min Stack
[Leetcode link](https://leetcode.com/problems/min-stack/description/)

### 34. Valid Parentheses
[Leetcode link](https://leetcode.com/problems/valid-parentheses/description/)

### 35. Evaluate Reverse Polish Notation
[Leetcode link](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)

### 36. Stack Sorting
[Leetcode link](https://leetcode.com/problems/longest-valid-parentheses/description/) *(Closest relevant problem)

## QUEUES
### 37. Implement Stack using Queues
[Leetcode link](https://leetcode.com/problems/implement-stack-using-queues/description/)

### 38. Time Needed to Buy Tickets
[Leetcode link](https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

### 39. Reverse the First K Elements of a Queue
*(Custom problem, no direct Leetcode link)*

## BINARY TREES
### 40. Average of Levels in Binary Tree
[Leetcode link](https://leetcode.com/problems/average-of-levels-in-binary-tree/description/)

### 41. Minimum Depth of Binary Tree
[Leetcode link](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)

### 42. Maximum Depth of Binary Tree
[Leetcode link](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)

### 43. Min/Max Value in Binary Tree
*(Closest match for Min/Max value in tree)*

### 44. Binary Tree Level Order Traversal
[Leetcode link](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)

### 45. Same Tree
[Leetcode link](https://leetcode.com/problems/same-tree/description/)

### 46. Path Sum
[Leetcode link](https://leetcode.com/problems/path-sum/description/)

### 47. Diameter of a Binary Tree
[Leetcode link](https://leetcode.com/problems/diameter-of-binary-tree/description/)

### 48. Invert Binary Tree
[Leetcode link](https://leetcode.com/problems/invert-binary-tree/description/)

### 49. Lowest Common Ancestor of a Binary Tree
[Leetcode link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)

## BINARY SEARCH TREES
### 50. Search in a Binary Search Tree
[Leetcode link](https://leetcode.com/problems/search-in-a-binary-search-tree/description/)

### 51. Insert into a Binary Search Tree
[Leetcode link](https://leetcode.com/problems/insert-into-a-binary-search-tree/description/)

### 52. Convert Sorted Array to Binary Search Tree
[Leetcode link](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/)

### 53. Two Sum IV - Input is a BST
[Leetcode link](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/)

### 54. Lowest Common Ancestor of a Binary Search Tree
[Leetcode link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

### 55. Minimum Absolute Difference in BST
[Leetcode link](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)

### 56. Balance a Binary Search Tree
[Leetcode link](https://leetcode.com/problems/balance-a-binary-search-tree/description/)

### 57. Delete Node in a BST
[Leetcode link](https://leetcode.com/problems/delete-node-in-a-bst/description/)

### 58. Kth Smallest Element in a BST
[Leetcode link](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

## HEAPS
### 59. Kth Largest Element in an Array
[Leetcode link](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

### 60. K Closest Points to Origin
[Leetcode link](https://leetcode.com/problems/k-closest-points-to-origin/description/)

### 61. Top K Frequent Elements
[Leetcode link](https://leetcode.com/problems/top-k-frequent-elements/description/)

### 62. Task Scheduler
[Leetcode link](https://leetcode.com/problems/task-scheduler/description/)

## GRAPHS
### 63. Breadth and Depth First Traversal
[Leetcode link](https://leetcode.com/problems/clone-graph/description/) *(Closest relevant problem)*

### 64. Clone Graph
[Leetcode link](https://leetcode.com/problems/clone-graph/description/)

### 65. Core Graph Operations
[Leetcode link](https://leetcode.com/problems/course-schedule/description/) *(Closest relevant problem)*

### 66. Cheapest Flights Within K Stops
[Leetcode link](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)
