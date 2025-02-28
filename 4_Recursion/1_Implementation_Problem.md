### 1. Pow(x,n)

```
Iterative Bruteforce
```

```
class Solution {
public:
    double myPow(double x, int n) {
        //your code goes here
        double ans = 1;
        if (n < 0){
            x= 1/x;
            n = -n;
        }
        for (int i=0; i<n; i++){
            ans *= x;
        }
        return ans;
    }
};
```

```
Recursive Optimal
```

```
class Solution {
    double power(double x, int n){
        if (n == 0) return 1;
        if (n == 1) return x;

        if (n % 2 == 0){
            return power(x * x, n/2);
        }

        return x * power(x, n-1);
    }
public:
    double myPow(double x, int n) {
        if (n < 0){
            return (1.0/ power(x, -1 * n));
        }
        return power(x, n);
    }
};
```

### 2. Generate Paranthesis
Given an integer n.Generate all possible combinations of well-formed parentheses of length 2 x N.

