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

```
Optimal [In Place]:
1. Take Transpose 
2. Reverse  the sub arrays
```

```
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        /*
            Input:
            [[1, 2, 3], 
             [4, 5, 6], 
             [7, 8, 9]]

            Take Transpose
             [[1, 4, 7], 
             [2, 5, 8], 
             [3, 6, 9]]

            Reverse
             [[7, 4, 1], 
             [8, 5, 2], 
             [9, 6, 3]]
        */
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i=0; i<matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

### 6. Two Sum
Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.

Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in non-decreasing order.

```
Bruteforce
```

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++){
            for (int j=0; j<i; j++){
                if (nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
    }
};
```

```
Optimal: Using Map  [ T: O(N) ] [ S: O(N) ]

1. Using Hashmap to store 
2. Finding Target-Num[i] in Hashmap 
```

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ans;

        for (int i=0; i<nums.size(); i++){
            int elem_to_search = target - nums[i];
            if (ans.find(elem_to_search) != ans.end()){
                return {i, ans[elem_to_search]};
            }
            ans[nums[i]] = i;
        }
    }
};
```

```
Optimal: Using Two Pointer Greedy Approach [ T: O(N) x O(NlogN) ] [ S: O(N*N) ]

If we don't want to return exact index, then this approach is better 
otherwise Map approach is better
```

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        vector<vector<int>> eIndex;
        for(int i = 0; i < nums.size(); i++){
            eIndex.push_back({nums[i], i});
        }
        
        sort(eIndex.begin(), eIndex.end(), 
            [](const vector<int>& a, const vector<int>& b) {
           return a[0] < b[0]; 
        });


        int left = 0, right = nums.size() - 1; 
        while (left < right) {
            int sum = eIndex[left][0] + eIndex[right][0];

            if (sum == target) {
                return {eIndex[left][1], eIndex[right][1]};     
            } else if (sum < target) {
                left++;
            } else {
                right--;  
            }
        }

        return {-1, -1};
    }
};
```

### 7. 3 Sum
Given an integer array nums.Return all triplets such that:

1. i != j, i != k, and j != k
2. nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets. One element can be a part of multiple triplets. The output and the triplets can be returned in any order.

```
Bruteforce
```

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        for (int i=0; i<nums.size()-2; i++){
            for (int j=i+1; j<nums.size()-1; j++){
                for (int k=j+1; k<nums.size(); k++){
                    if (nums[i] + nums[j] + nums[k] == 0 && i!=j && i!=k && j!=k){
                        ans.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        vector<vector<int>> answer(ans.begin(), ans.end());
        return answer;
    }
};
```

```
Better: Using Set with math equation a+b = - c 
```

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        for (int i=0; i<nums.size(); i++){
            set<int> hashset;
            for (int j=i+1; j<nums.size(); j++){
                int third = -(nums[i] + nums[j]);
                if (hashset.end() != hashset.find(third)){
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                hashset.insert(nums[j]);
            }
            
        }
        vector<vector<int>> answer(ans.begin(), ans.end());
        return answer;
    }
};
```

```
Optimal: Using two pointer 
```

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = nums.size() - 1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0){
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    ans.push_back(temp);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                } else if (sum > 0){
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};
```

### 8. 4 Sum
Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

1. a, b, c, d are all distinct valid indices of nums.
2. nums[a] + nums[b] + nums[c] + nums[d] == target.

Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.

```
Bruteforce
```

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        for (int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++){
                for (int k=j+1; k<nums.size(); k++){
                    for (int l=k+1; l<nums.size(); l++){
                        int sum = nums[i]+nums[j]+nums[k]+nums[l];
                        if (sum == target){
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            ans.insert(temp);
                        }

                    }
                }
            }
        }
        vector<vector<int>> answer(ans.begin(), ans.end());
        return answer;
    } 
};
```

```
Better
```

```
Optimal: Using Two Pointer 
```

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++){
            // Skip duplictaes for i
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j=i+1; j<nums.size(); j++){
                // Skip duplictaes for j
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1;
                int right = nums.size() - 1;
                while (left<right){
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if (sum > target){
                        right--;
                    } else if (sum < target){
                        left++;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        ans.push_back(temp);
                        right--;
                        left++;
                        while (left<right && nums[left] == nums[left-1]) left++;
                        while (left<right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }
        return ans;
    } 
};
```

### 9. Sort an array of 0's 1's and 2's
Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array.

```
Bruteforce [ T: (OlogN) ] [ S: O(1) ]
```

```
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
```

```
Better [ T: O(N)+ O(N) = O(2N) ]
```

```
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 0){
                zeros++;
            } else if (nums[i] == 1){
                ones++;
            } else {
                twos++;
            }
        } 


        for (int i=0; i<zeros; i++){
            nums[i] = 0;
        }
        for (int j=zeros; j<zeros+ones; j++){
            nums[j] = 1;
        }
        for (int k=zeros+ones; k<nums.size(); k++){
            nums[k] = 2;
        }
    }
};
```