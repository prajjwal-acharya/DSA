# Combination Sum II - Optimized Approach (C++)

## Overview
This program solves the **Combination Sum II** problem using **Recursion and Backtracking** in an optimized way. It eliminates duplicate combinations **during recursion itself** instead of filtering them afterward.

## Problem Statement
Given an array of **candidates** (which may contain duplicates) and a target integer `target`, return **all unique combinations** where the sum of the chosen numbers equals `target`. Each number in `candidates` **can only be used once**.

## Approach
1. **Sort the array** to handle duplicates efficiently.
2. **Use a loop inside the recursive function** to generate combinations.
3. **Skip duplicates directly in recursion** (`if(i > ind && arr[i] == arr[i - 1]) continue;`).
4. **Break early (`if(arr[i] > target) break;`)** to avoid unnecessary recursive calls.

## Code Explanation

### **Class: `Solution`**
This class contains two methods:
1. `findCombination()`: A recursive function that generates unique valid combinations.
2. `combinationSum2()`: Calls `findCombination()` and returns the final answer.

### **Recursive Function: `findCombination()`**
```cpp
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i = ind; i < arr.size(); i++){
        if(i > ind && arr[i] == arr[i - 1]) continue;  // Skip duplicate elements
        if(arr[i] > target) break;  // Break if current element exceeds target
        
        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();  // BACKTRACK
    }
}
```

### **Time & Space Complexity**
- **Sorting Complexity:** `O(n log n)`
- **Recursion Complexity:** `O(2^n * k)`
- **Space Complexity:** `O(k * x)`

## **Why is This Approach Better?**
- **Prevents duplicate combinations at recursion level** instead of filtering later.
- **Breaks early** if `arr[i] > target`, avoiding unnecessary recursion.
- **Uses a loop instead of `set`**, reducing space complexity.

## **Conclusion**
This optimized approach efficiently finds all unique combinations using recursion and backtracking while avoiding redundant computations.

