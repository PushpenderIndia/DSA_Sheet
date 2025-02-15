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

```

```
Solution Intuition: Sort Array and then Check Current element 
```

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