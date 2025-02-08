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

### 2. 
