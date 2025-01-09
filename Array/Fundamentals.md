### 1. Linear Search
Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. If the target is not found in the array, return -1.

```
class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};
```

### 2. Largest Element
Given an array of integers nums, return the value of the largest element in the array.

```
class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largestElement = nums[0];
        for (int i=0; i<nums.size(); i++){
            if (largestElement < nums[i]){
                largestElement = nums[i];
            }
        }
        return largestElement;
    }
};
```

### 3. Second Largest Element
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

```
Brute Force: 
1. Sort Array, 2nd Largest Index will be -2
2. Edge Case: Array Less than 2, Return -1
3. Iterate & Check Number from last 
```

```
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int secondLargest = INT_MIN;
        sort(nums.begin(), nums.end());
        int largestElement = nums.back();
        for (int i=0; i < nums.size(); i++){
            if (largestElement != nums[i] && secondLargest < nums[i]){
                secondLargest = nums[i];
            }
        }
        if (secondLargest == INT_MIN){
            return -1;
        }
        return secondLargest;
    }
};
```

```
Better: Two Loops, 1st for Finding LargestElement & 2nd for Finding SecondLargest
Better Approach because eliminating sorting
```

```
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int largestElement = nums[0];
        for (int i=0; i<nums.size(); i++){
            if (largestElement < nums[i]) {
                largestElement = nums[i];
            }
        }

        int secondLargest = INT_MIN;
        for (int i=0; i<nums.size(); i++){
            if (largestElement != nums[i] && nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }

        if (secondLargest == INT_MIN){
            return -1;
        }
        return secondLargest;
    }
};
```

```
Optimal: Initialize two Variables Largest & SecondLargest, make smart comparison within single traversal
```

```
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int largestElement = INT_MIN;
        int secondLargest = INT_MIN;
        for (int i=0; i<nums.size(); i++){
            if (largestElement < nums[i]) {
                largestElement = nums[i];
            }

            else if (secondLargest < nums[i] && nums[i] != largestElement){
                secondLargest = nums[i];
            }
        }

        if (secondLargest == INT_MIN){
            return -1;
        }
        return secondLargest;
    }
};
```

### 4. Maximum Consecutive Ones
Given a binary array nums, return the maximum number of consecutive 1s in the array.
A binary array is an array that contains only 0s and 1s.

```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1s = 0;  
        int maxCount = 0;  

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                max1s++;  
                maxCount = max(maxCount, max1s); 
            } else {
                max1s = 0;  
            }
        }

        return maxCount; 
    }
};
```

### 5. Left Rotate Array by One
Given an integer array nums, rotate the array to the left by one.

