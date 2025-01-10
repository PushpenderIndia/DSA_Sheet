### 1. Move Zeros to End
Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same. This must be done in place, without making a copy of the array.

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzero = 0;
        int a = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] != 0){
                nums[a] = nums[i];
                a++;
                nonzero++;
            }
        }

        for (int i=nonzero; i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};
```

### 2. Remove duplicates from sorted array
Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once. Return the number of unique elements in the array.

If the number of unique elements be k, then,

Change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally.
The remaining elements, as well as the size of the array does not matter in terms of correctness.

An array sorted in non-decreasing order is an array where every element to the right of an element in either equal to or greater in value than that element.

```
Bruteforce: O(NlogN) + O(N) for using Hashset & Single array traversal.
```

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> unique;
        for (int i=0; i<nums.size(); i++){
            unique.insert(nums[i]);
        }

        int j = 0;
        for (int val : unique){
            nums[j] = val;
            j++;
        }

        return unique.size();
    }
};
```

```
Optimal
```

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for (int i=1; i<nums.size(); i++){
            if (nums[j] != nums[i]){  
                j++;
                nums[j] = nums[i]; 
            } 
        }
        return j+1;
    }
};
```

### 3. Find missing number
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.

```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++){
            if (nums[i] != i){
                return i;
            }
        }
        return nums.size();
    }
};
```

### 4. Union of two sorted arrays
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.

The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

```
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int> all;
        for (int val : nums1 ) {
            all.insert(val);
        } 
        for (int val1 : nums2 ) {
            all.insert(val1);
        } 

        vector<int> result;
        for (int val2: all ){
            result.push_back(val2);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
```

### 5. Intersection of two sorted arrays
Given two sorted arrays nums1 and nums2, return an array containing the intersection of these two arrays.

The intersection of two arrays is an array where all values are present in both arrays.

