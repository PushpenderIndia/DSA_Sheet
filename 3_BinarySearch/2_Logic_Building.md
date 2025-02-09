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
class Solution {
public:
    int findMin(vector<int> &arr)  {
        int min_ans = INT_MAX;
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low<=high){
            int mid = (low+high)/2;
            if (arr[low] <= arr[mid]){
                min_ans = min(min_ans, arr[low]);
                low = mid + 1;
            } else {
                min_ans = min(min_ans, arr[mid]);
                high = mid - 1;
            }
        }
        return min_ans;
    }
};
```

### 7. Find out how many times the array is rotated
Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 1 and n. Determine the number of rotations performed on the array.

```
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int min_num = INT_MAX;
        int min_num_index = -1;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[low] <= nums[high]){
                if (nums[low] < min_num){
                    min_num = nums[low];
                    min_num_index = low;
                }
                break;
                
            } 
            else if (nums[low] <= nums[mid]){
                if (nums[low] < min_num){
                    min_num = nums[low];
                    min_num_index = low;
                }
                low = mid + 1;
            } 
            
            else {
                if (nums[mid] < min_num){
                    min_num = nums[mid];
                    min_num_index = mid;
                }
                high = mid - 1;
            }
        }
        return min_num_index;
    }
};
```

### 8. Single element in sorted array
Given an array nums sorted in non-decreasing order. Every number in the array except one appears twice. Find the single number in the array.

```
Bruteforce: T: O(2N) S: O(N)
```

```
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        map<int, int> freq;
        for (int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        for (int i=0; i<nums.size(); i++){
            if (freq[nums[i]] == 1){
                return nums[i];
            }
        }
        return -1;
    }
};
```

```
Better: XOR (XOR all elements will give us single non-duplicate num)
T: O(N) S: O(1)

XOR:  
A ^ A = 0
A ^ 0 = A 

thus all duplicate's XOR will become 0, and single non dup's XOR with 0 with Return that number itself
```

```
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
```

```
Optimal
```

```
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();

        // Edge case
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1;
        int high = n - 2;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }

            if ((mid % 2 == 1 && nums[mid] == nums[mid-1])
                || (mid % 2 == 0 && nums[mid] == nums[mid+1])){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
```

