### 1. Find row with maximum 1's
Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.

```
class Solution {
private:
    //Helper function to find the lower bound of 1.
    int lowerBound(vector<int> arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            
            /* If element at mid is greater than or equal 
            to x then it could be a possible answer.*/
            if (arr[mid] >= x) {
                ans = mid;
                
                //Look for smaller index on the left
                high = mid - 1;
            }
            else {
                low = mid + 1; 
            }
        }
        //Return the answer
        return ans;
    }
public:
    /* Function to find the row 
    with the maximum number of 1's*/
    int rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        /* Variable to store the 
        maximum count of 1's found*/
        int cnt_max = 0; 
        
        /* Variable to store the index
        of the row with max 1's*/
        int index = -1;  

        //Traverse each row of the matrix
        for (int i = 0; i < n; i++) {
            // Get the number of 1's
            int cnt_ones = m - lowerBound(mat[i], m, 1);
            
            /*If the current count is greater than 
            maximum, store the index of current row
            and update the maximum count.*/
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        /* Return the index of the row 
        with the maximum number of 1's*/
        return index;
    }
};
```

### 2. Search in a 2D matrix
Given a 2-D array mat where the elements of each row are sorted in non-decreasing order, and the first element of a row is greater than the last element of the previous row (if it exists), and an integer target, determine if the target exists in the given mat or not.

```
class Solution{
    bool doesexits(vector<int>& nums, int target){
        int low = 0;
        int high =nums.size()-1;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid] == target){
                return true;
            }
            else if (nums[mid] > target){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        for (int i=0; i<mat.size(); i++){
            if(doesexits(mat[i], target)){
                return true;
            }
        }
        return false;
    }
};
```

### 3. Search in 2D matrix - II
Given a 2D array matrix where each row is sorted in ascending order from left to right and each column is sorted in ascending order from top to bottom, write an efficient algorithm to search for a specific integer target in the matrix.

```
class Solution {
public:
    //Function to search for a given target in matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        //Intialize the row and col
        int row = 0, col = m - 1;

        //Traverse the matrix from (0, m-1):
        while (row < n && col >= 0) {
            
            //Return true of target is found
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }
        //Return false if target not found
        return false;
    }
};
```

### 4. Find Peak Element
Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j].A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.

Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

```
class Solution {
public:
    /* Helper function to find the index of the row
    with the maximum element in a given column*/
    int maxElement(vector<vector<int>>& arr, int col) {
        int n = arr.size();
        int max_val = INT_MIN;
        int index = -1;
        
        /* Iterate through each row to find the
        maximum element in the specified column*/
        for (int i = 0; i < n; i++) {
            if (arr[i][col] > max_val) {
                max_val = arr[i][col];
                index = i;
            }
        }
        // Return the index
        return index;
    }
    
    /* Function to find a peak element in 
     the 2D matrix using binary search */
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int n = arr.size();     
        int m = arr[0].size();  
        
        /* Initialize the lower bound for 
        and upper bound for binary search */
        int low = 0;           
        int high = m - 1;      
        
        // Perform binary search on columns
        while (low <= high) {
            int mid = (low + high) / 2;  
            
            /* Find the index of the row with the 
            maximum element in the middle column*/
            int row = maxElement(arr, mid);
            
            /* Determine the elements to left and 
            right of middle element in the found row */
            int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;
            
            /* Check if the middle element 
             is greater than its neighbors */
            if (arr[row][mid] > left && arr[row][mid] > right) {
                return {row, mid};  
            } 
            else if (left > arr[row][mid]) {
                high = mid - 1;  
            } 
            else {
                low = mid + 1;
            }
        }
        
        // Return {-1, -1} if no peak element is found
        return {-1, -1};  
    }
};
```

### 5. Matrix Median
Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.

```
class Solution {
private:
    //Function to find the upper bound of an element
    int upperBound(vector<int>& arr, int x, int m) {
        int low = 0, high = m - 1;
        int ans = m;
        
        //Apply binary search
        while (low <= high) {
            int mid = (low + high) / 2;
            
            /* If arr[mid] > x, it 
            can be a possible answer*/
            if (arr[mid] > x) {
                ans = mid;
                //Look for smaller index on the left
                high = mid - 1;
            }
            else {
                low = mid + 1; 
            }
        }
        //Return the answer
        return ans;
    }
    /*Function to find the count of 
    element smaller than x or equal to x*/
    int countSmallEqual(vector<vector<int>>& matrix, int n, int m, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(matrix[i], x, m);
        }
        //Returnt the count
        return cnt;
    }
public:
    //Function to find the median in a matrix
    int findMedian(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        //Intialize low and high
        int low = INT_MAX, high = INT_MIN;

        //Point low and high to right elements
        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        int req = (n * m) / 2;
        
        //Perform binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            /*Store the count of elements
            lesser than or equal to mid*/
            int smallEqual = countSmallEqual(matrix, n, m, mid);
            if (smallEqual <= req) low = mid + 1;
            else high = mid - 1;
        }
        //Return low as answer
        return low;
    }
};
```

