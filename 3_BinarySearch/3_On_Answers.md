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

### 8. Find peak element
Given an array arr of integers. A peak element is defined as an element greater than both of its neighbors. Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i]. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

```
Bruteforce: O(N)
```

```
class Solution {
public:
    int findPeakElement(vector<int> &arr) {
        int n = arr.size();
        for (int i=0; i<n; i++){
            if ((i == 0 || arr[i-1] < arr[i]) && 
                (i == n -1 || arr[i] > arr[i+1])){
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
    int findPeakElement(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n-1] > arr[n-2]) return n - 1;

        int low = 1;
        int high = n - 2;
        while (low<=high){
            int mid = (low+high)/2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;

            if (arr[mid] > arr[mid - 1]) low = mid + 1;

            else high = mid - 1;
        }
        return -1;
    }
};
```

### 9. Median of 2 sorted arrays (Very Hard)
Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays.

The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

```
Bruteforce: T: O(NlogN) S: O(N + M)
```

```
class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        vector<int> merged(arr1.begin(), arr1.end());
        for (int i=0; i<arr2.size(); i++){
            merged.push_back(arr2[i]);
        }
        sort(merged.begin(), merged.end());

        int n = merged.size();
        if (n % 2 != 0) return merged[n/2]; 
        else {
            int first = merged[(int)n/2];
            int second = merged[((int)n/2)-1];
            return (double)(first+second)/2;
        }
    }
};
```

```
Optimal: Need to Determine the left haft of merged array
Observation: 
------------
left half will surely contain x elements from arr1[] & 
(n/2)-x elements from arr2[]

x range ==> [0, n1], where n1 == size of arr1[]
```

```
class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();

        if (n1 > n2) return median(arr2, arr1);

        int n = n1 + n2;

        int left = (n1 + n2 + 1)/2;
        int low = 0;
        int high = n1;
        while (low <= high){
            int mid1 = (low+high) >> 1;
            int mid2 = left - mid1;

            int l1 = (mid1 > 0) ? arr1[mid1 - 1]: INT_MIN;
            int r1 = (mid1 < n1) ? arr1[mid1] : INT_MAX;
            int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? arr2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return max(l1, l2);
                else return (max(l1, l2) + min(r1, r2)) / 2.0;
            } 
            else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0; 
    }
};
```

### 10. Minimise max distance to gas stations (Very Hard - Rare in interviews)
Given a sorted array arr of size n, containing positive integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis. The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions. Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations. Find the minimum value of dist.

```
Intuition: For Minimising max dist, we need to place new gas stations without existing gas stations
If lets say we have [1, 13, 17, 23] and k = 5
then we have gaps dist of 12 (13-1), 4 (17-13), 6 (23-17)
We will place 1 gs b/w 1 & 13, k left = 4 (5-1)
New gaps 6 ((13-1)/2), 4, 6
We need to minimize gap of 6, thus we will place 1 more b/w 1 & 13
New gaps 4 ((13-1)/3), 4, 6
Need to minimize gap of 6 b/w 17 & 23 and so on, we will get 
We need to place 3 gs b/w 1 & 13 ==> Max Gap ==> 3
1 gs b/w 13 & 17 ==> Max Gap ==> 2
1 gs b/w 17 & 23 ==> Max Gap ==> 3
Output: 3
```

```
Bruteforce: [T: O(k*N) + O(N)] [S: O(N-1)]
```

```
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n-1, 0);
        for (int gasStations=1; gasStations<=k; gasStations++){
            double maxSection = -1;
            int maxInd = -1;

            for (int i=0; i<n-1; i++){
                double diff = arr[i+1] - arr[i];
                double sectionLength = diff / (howMany[i]+1);

                if (sectionLength > maxSection){
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }
            howMany[maxInd]++;
        }    

        double maxAns = -1;
        for (int i=0; i<n-1; i++){
            double diff = arr[i+1] - arr[i];
            double sectionLength = diff / (howMany[i] + 1);
            maxAns = max(maxAns, sectionLength);
        }

        return maxAns;
    }
};
```

```
Better: Using priority_queue (Heap DS) for calculating the MaxGap
T: O(NlogN + klogN)
S: O(N-1)+O(N-1)
```

```
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n-1, 0);
        priority_queue<pair<long double, int>> pq;

        for (int i=0; i<n-1; i++){
            pq.push({(long double)(arr[i+1] - arr[i]), i});
        }

        for (int gasStations=1; gasStations<=k; gasStations++){
            auto tp = pq.top();
            pq.pop();
            int secInd = tp.second;
            howMany[secInd]++;

            long double inidiff = (long double)(arr[secInd + 1] - arr[secInd]);

            long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);

            pq.push({newSecLen, secInd});
        }    

        return pq.top().first;
    }
};
```

```
Optimal
```

```
class Solution {
private:
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int n = arr.size(); 
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            
            int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
            
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            
            cnt += numberInBetween;
        }
        return cnt;
    }
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size(); 
        long double low = 0;
        long double high = 0;

        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        long double diff = 1e-6;
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);

            if (cnt > k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};
```

### 11. 