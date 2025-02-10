### 1. Find square root of a number
Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).

```
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long floorSqrt(long long n) {
        long long low = 1, high = n;
        
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = mid * mid;
            
            if (val <= (long long)(n)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return high;
    }
};
```

### 2. Find Nth root of a number
Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.

```
Bruteforce: T: O(N) S: O(1)
```

```
class Solution {
public:
  int NthRoot(int N, int M) {
       for (int i=1; i<M; i++){
            if (pow(N, i) == M){
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
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helperFunc(int mid, int n, int m) {
        long long ans = 1, base = mid;
        
        while (n > 0) {
            if (n % 2) {
                ans = ans * base;
                if (ans > m) return 2;  // Early exit
                n--;
            } 
            else {
                n /= 2;
                base = base * base;
                if(base > m) return 2;
            }
        }
        if (ans == m) return 1;
        return 0;
    }
 
public:
    int NthRoot(int N, int M) {
        int low = 1, high = M;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int midN = helperFunc(mid, N, M);
            
            if (midN == 1) {                
                return mid;
            } 
            else if (midN == 0) {
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

### 3. Find the smallest divisor
Given an array of integers nums and an integer limit as the threshold value, find the smallest positive integer divisor such that upon dividing all the elements of the array by this divisor, the sum of the division results is less than or equal to the threshold value.

Each result of the division is rounded up to the nearest integer greater than or equal to that element.

```
class Solution {
    int helper(vector<int> &nums, int divisor){
        int sum = 0;
        for (int i=0; i<nums.size(); i++){
            sum += ceil((double)(nums[i]) / (double)(divisor));
        }
        return sum;
    }
public:
  int smallestDivisor(vector<int> &nums, int limit) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low<=high){
            int mid = (low+high)/2;
            int val = helper(nums, mid);
            if (val <= limit){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }  
        return low;
    }
};
```

### 4. Koko eating bananas
A monkey is given n piles of bananas, where the 'ith' pile has nums[i] bananas. An integer h represents the total time in hours to eat all the bananas.

Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas. If the pile contains fewer than k bananas, the monkey eats all the bananas in that pile and does not consume any more bananas in that hour.

Determine the minimum number of bananas the monkey must eat per hour to finish all the bananas within h hours.

```
class Solution {
    bool canEatInTime(vector<int> &nums, int eat_rate, int h){
        int total_hour = 0;
        for (int i=0; i<nums.size(); i++){
            total_hour += ceil((double)nums[i] / (double)eat_rate);
            if (total_hour > h) return false;
        }
        return true;
    }
public:
int minimumRateToEatBananas(vector<int> nums, int h) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = INT_MIN;
        while (low<=high){
            int mid = (low+high)/2;
            bool val = canEatInTime(nums, mid, h);
            if (val){
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

### 5. Minimum days to make M bouquets
Given n roses and an array nums where nums[i] denotes that the 'ith' rose will bloom on the nums[i]th day, only adjacent bloomed roses can be picked to make a bouquet. Exactly k adjacent bloomed roses are required to make a single bouquet. Find the minimum number of days required to make at least m bouquets, each containing k roses. Return -1 if it is not possible.

```
class Solution {
    bool canWeMakeBouquets(vector<int> &nums, int k, int m, int daysAfter) {
        int countBouquets = 0;
        int countAdjustantEle = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= daysAfter) {
                countAdjustantEle++;
                if (countAdjustantEle == k) { 
                    countBouquets++;
                    countAdjustantEle = 0; 
                    if (countBouquets == m) return true; 
                }
            } else {
                countAdjustantEle = 0; 
            }
        }
        return countBouquets >= m;
    }
public:
int roseGarden(int n,vector<int> nums, int k, int m) {
        if ((k * m) > n) return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = INT_MIN;
        while (low<=high){
            int mid = (low + high)/2;
            if (canWeMakeBouquets(nums, k, m, mid)){
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

### 6. Aggressive Cows
Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.

```
Bruteforce
```

```
class Solution {
    bool canWePlaceCow(vector<int> &nums, int k, int dist){
        int n = nums.size();
        int cout_Cows = 1;
        int last = nums[0];
        for(int i=1; i<n; i++){
            if (nums[i] - last >= dist){
                cout_Cows++;
                last = nums[i];
            }
            if (cout_Cows >= k) return true;
        }
        return false;
    }
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int limit = nums[n-1] - nums[0];
        for (int i=1; i<limit; i++){
            if (!canWePlaceCow(nums, k, i)){
                return i - 1;
            }
        }
        return limit;
    }
};
```

```
Optimal: T: O(NlogN) S: O(1)
```

```
class Solution {
    bool canWePlaceCow(vector<int> &nums, int k, int dist){
        int n = nums.size();
        int cout_Cows = 1;
        int last = nums[0];
        for(int i=1; i<n; i++){
            if (nums[i] - last >= dist){
                cout_Cows++;
                last = nums[i];
            }
            if (cout_Cows >= k) return true;
        }
        return false;
    }
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1;
        int high = nums[n-1] - nums[0];
        int ans;
        while (low<=high){
            int mid = (low+high)/2;
            if (canWePlaceCow(nums, k, mid)){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};
```

### 7. Book Allocation Problem (Very Hard Ques)
Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.

Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.

```
Bruteforce
```

```
class Solution {
    int helper(vector<int> &nums, int pages){
        int std = 1;
        int pagesStudent = 0;
        for (int i=0; i<nums.size(); i++){
            if (pagesStudent + nums[i] <= pages){
                pagesStudent += nums[i];
            }
            else {
                std++;
                pagesStudent = nums[i];
            }
        }
        return std; 
    }
public:
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();

        if (n < m) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        for (int i=low; i<=high; i++){
            if (helper(nums, i) == m) return i;
        }
        return low;
    }
};
```

```
Optimal
```

```
class Solution {
    int helper(vector<int> &nums, int pages){
        int std = 1;
        int pagesStudent = 0;
        for (int i=0; i<nums.size(); i++){
            if (pagesStudent + nums[i] <= pages){
                pagesStudent += nums[i];
            }
            else {
                std++;
                pagesStudent = nums[i];
            }
        }
        return std; 
    }
public:
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();

        if (n < m) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low<=high){
            int mid = (low+high)/2;
            int val = helper(nums, mid);
            if (val > m) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};
```

