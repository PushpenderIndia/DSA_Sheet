### 1. Search X in sorted array
Given a sorted array of integers nums with 0-based indexing, find the index of a specified target integer. If the target is found in the array, return its index. If the target is not found, return -1.

```
Optimal: T : (logN) S: O(1)
```

```
class Solution{
public:
    int search(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high){
            int mid = (low + high)/ 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                high = mid - 1;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
        }
        return -1;
    }
};
```

```
Optimal Using recursive binary search
```

```
class Solution{

int recursive_bs(vector<int> &nums, int low, int high, int target){
    if (low > high){
        return -1;
    }
    
    int mid = (low + high)/2;
    int index;
    if (nums[mid] == target){
        return mid;
    }
    else if (nums[mid] > target){
        index = recursive_bs(nums, low, mid-1, target);
    } 
    else if (nums[mid] < target){
        index = recursive_bs(nums, mid+1, high, target);
    }
    return index;
}

public:
    int search(vector<int> &nums, int target){
        int n = nums.size();
        return recursive_bs(nums, 0, n-1, target);
    }
};
```

### 2. Lower Bound
Given a sorted array of nums and an integer x, write a program to find the lower bound of x. The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

If no such index is found, return the size of the array.

```
NOTE: Lower Bound of X is num which Greater Than or Equal to X
```

```
class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n -1;
        int ans = nums.size();
        while (low <= high){
            int mid = (low + high)/2;
            if (nums[mid] >= x){
                ans = mid;
                high = mid -1;
            } 
            else if (nums[mid] < x){
                low = mid + 1;
            }
        }
        return ans;
    }
};
```

### 3. Upper Bound
Given a sorted array of nums and an integer x, write a program to find the upper bound of x. The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than a given key i.e. x.

If no such index is found, return the size of the array.

```
NOTE: Upper Bound of X is num which Smaller Than X
```

```
class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans;
        while (low <= high){
            int mid = (low + high)/2;
            if (nums[mid] > x){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
```
