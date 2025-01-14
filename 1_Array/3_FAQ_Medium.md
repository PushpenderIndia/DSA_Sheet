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

### 3. Rearrange array elements by sign
Given an integer array nums of even length consisting of an equal number of positive and negative integers.Return the answer array in such a way that the given conditions are met:

1. Every consecutive pair of integers have opposite signs.
2. For all integers with the same sign, the order in which they were present in nums is preserved.
3. The rearranged array begins with a positive integer.

```
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] > 0){
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }

        bool ispositive = true;
        int a = 0;
        int j = 0;
        for (int i=0; i<nums.size(); i++){
            if (ispositive){
                nums[i] = pos[a];
                a++;
                ispositive = false;
            } else {
                nums[i] = neg[j];
                j++;
                ispositive = true;
            }
        }
        return nums;
    }
};
```

### 4. Pascal's Triangle
Given an integer numRows return the first numRows rows of Pascal's triangle.

In Pascal's triangle:
1. The first row has one element with a value of 1.
2. Each row has one more element in it than its previous row.
3. The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

```
class Solution {
public:
    vector<vector<int>> pascalTriangle(int numRows) {
        /*
             1
            1 1
           1 2 1
          1 3 3 1
         1 4 6 4 1  
        */
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i=1; i<numRows; i++){
            vector<int> subans;
            for (int j=0; j<=i; j++) {
                if (j == 0 || j == i){
                    subans.push_back(1);
                } else {
                    subans.push_back(ans[i-1][j] + ans[i-1][j-1]);
                }
            }
            ans.push_back(subans);
        }
        return ans;
    }
};
```

### 5. Rotate matrix by 90 degrees
Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.

The rotation must be done in place, meaning the input 2D matrix must be modified directly.

```
Bruteforce: Using a new matrix, storing result and then copying them to original matrix 
```

```
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        for (int j=0; j<matrix.size(); j++){ 
            vector<int> subans;
            for (int i=matrix[0].size()-1; i>=0; i--){
                subans.push_back(matrix[i][j]);
            }
            ans.push_back(subans);
        }

        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};
```

``