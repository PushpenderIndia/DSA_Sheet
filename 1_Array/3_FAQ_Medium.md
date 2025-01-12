### 1. Leaders in an Array
Given an integer array nums, return a list of all the leaders in the array.

A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

```
Bruteforce
```

```
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;

        for (int i=0; i<nums.size(); i++){
            bool currentLeader = true;
            for (int j=i; j<nums.size(); j++){
                if (nums[i] < nums[j]){
                    currentLeader = false;
                    break;
                }
            }

            if (currentLeader){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
```

```
Optimal: 

1. Set max to the last element of the array (nums[sizeOfArray - 1]) since it is always a leader.
2. Initialize an empty list ans and add the last element to it.
3. Iterate from the second last element (index = sizeOfArray - 2) to the first (index = 0).
4. For each element: If the element is greater than max, add it to ans and update max.
5. The ans list contains all leader elements in the array's order.
```

```
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;

        int leader = nums[nums.size()-1];
        ans.push_back(leader);
        for (int i=nums.size()-1; i>=0; i--){
           if (leader < nums[i]){
                leader = nums[i];
                ans.push_back(nums[i]);
           }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

### 2. Print the matrix in spiral manner
Given an M * N matrix, print the elements in a clockwise spiral manner. Return an array with the elements in the order of their appearance when printed in a spiral manner.

```
NOTE: Only 1 solution, Ratt Lo BC
```

```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top  = 0;
        int left = 0;
        int bottom = matrix.size() - 1; // No of rows
        int right  = matrix[0].size() - 1; // No of columns
        while (top <= bottom && left <= right){
            // Left to Right
            for (int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Top to Bottom
            for (int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                // Right to Left
                for (int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right){
                // Bottom to Top
                for (int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            } 
        }
        return ans;
    }
};
```