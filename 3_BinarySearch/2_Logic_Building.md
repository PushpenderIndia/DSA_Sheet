### 1. Search insert position
Given a sorted array of nums consisting of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

```
class Solution {
public:
    int searchInsert(vector<int> &nums, int target)  {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while (low <= high){
            int mid = (low+high)/2;
            if (nums[mid] == target){
                return mid;
            } 
            else if (nums[mid] > target){
                high = mid -1;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
        }
        return low;
    }
};
```

### 2. Floor and Ceil in Sorted Array
Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.

```
class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor = -1; // Smaller Than Equal to X
        int ceil = -1; // Greater than Equal to X
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high){
            int mid = (low+high)/2;
            if (nums[mid] == x){
                floor = nums[mid];
                ceil = nums[mid];
                break;
            }

            else if (nums[mid] > x){
                high = mid - 1;
                ceil = nums[mid];
            }
            else if (nums[mid] < x){
                low = mid + 1;
                floor = nums[mid];
            }
        }
        return {floor, ceil};
    }
};
```

### 3. First and last occurrence
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If the target is not found in the array, return [-1, -1].

```
class Solution{
    int lowerBound(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = nums.size();
        while (low <= high){
            int mid = (low + high)/2;
            if (nums[mid] >= target){
                ans = mid;
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = nums.size();
        while (low <= high){
            int mid = (low + high)/2;
            if (nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int firstOccur = lowerBound(nums, target);
        if (firstOccur == nums.size() || nums[firstOccur] != target){
            return {-1, -1};
        }
        int lastOccur = upperBound(nums, target) - 1;
        return {firstOccur, lastOccur};
    }
};
```

### 4. Search in rotated sorted array-I
Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.

```
Bruteforce: O(N): Linear search 
```

```
class Solution {
public:
    int search(vector<int> &nums, int k) {
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == k){
                return i;
            }
        }
        return -1;
    }
};
```

```
Optimal
```

```
class Solution {
public:
    int search(vector<int> &nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high){
            int mid = (low+high)/2;
            if (nums[mid] == k){
                return mid;
            }
            else if (nums[low] < nums[mid]){
                if (nums[low] <= k && nums[mid] >= k){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (nums[mid] <= k && nums[high] >= k){
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            
        }
        return -1;
    }
};
```

### 5. Search in rotated sorted array-II
Given an integer array nums, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

```
class Solution {
public:
    bool searchInARotatedSortedArrayII(vector<int> &nums, int k)  {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high){
            int mid = (low+high)/2;
            if (nums[mid] == k){
                return true;
            }
            
            if (nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }

            if (nums[low] <= nums[mid]){
                if (nums[low] <= k && nums[mid] >= k){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (nums[mid] <= k && nums[high] >= k){
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
```

### 6. Find minimum in Rotated Sorted Array
Given an integer array nums of size N, sorted in ascending order with distinct values, and then rotated an unknown number of times (between 1 and N), find the minimum element in the array.

```
Using min_element() : Not ideal for interview
```

```
class Solution {
public:
    int findMin(vector<int> &arr)  {
        auto it = min_element(arr.begin(), arr.end());
        return *it;
    }
};
```

```
```
