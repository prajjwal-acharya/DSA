# Combination Sum II - Naïve Approach (C++)

## Overview

This program solves the **Combination Sum II** problem using **Recursion and Backtracking** but follows a **naïve approach** that removes duplicates using a `set<vector<int>>` instead of avoiding them during recursion.

## Problem Statement

Given an array of **candidates** (which may contain duplicates) and a target integer `target`, return **all unique combinations** where the sum of the chosen numbers equals `target`. Each number in `candidates` **can only be used once**.

## Approach

1. **Sort the array** to help manage duplicate elements.
2. **Recursively generate all combinations** that sum to `target`.
3. **Use a **`` to eliminate duplicate combinations.
4. **Convert the **``** to a **`` for output.

## Code Explanation

### **Class: **``

This class contains two methods:

1. `findCombinations()`: A recursive function that generates all valid combinations.
2. `combinationSum2()`: Calls `findCombinations()` and returns the final answer.

### **Recursive Function: **``

```cpp
void findCombinations(int ind, int target, vector<int> &arr, set<vector<int>> &ans, vector<int> &ds){
    if(ind == arr.size()){  // Base Case
        if(target == 0){
            ans.insert(ds); // Store unique combination
        }
        return;
    }
    
    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findCombinations(ind + 1, target - arr[ind], arr, ans, ds);
        ds.pop_back(); // BACKTRACK
    }
    
    findCombinations(ind + 1, target, arr, ans, ds);
}
```

- **Generates duplicate combinations, later removed using a **``**.**
- **Backtracks by removing the last element (**``**).**

### **Function: **``

```cpp
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    set<vector<int>> ans;
    vector<int> ds;
    vector<vector<int>> answer;
    
    findCombinations(0, target, candidates, ans, ds);
    answer.assign(ans.begin(), ans.end());
    return answer;
}
```

- **Sorting helps group duplicate elements together.**
- **Uses **``** to remove duplicate combinations, which is inefficient.**

### **Time & Space Complexity**

- **Sorting Complexity:** `O(n log n)`
- **Recursion Complexity:** `O(2^n * k)`
- **Space Complexity:** `O(k * x)` (Extra space used due to `set`)

## **Why is This Approach Naïve?**

1. **Inefficient Duplicate Removal:** Instead of avoiding duplicates while generating combinations, it removes them afterward using `set`, leading to extra space usage.
2. **Unnecessary Sorting:** Sorting helps, but a **better approach exists** to manage duplicates during recursion itself.
3. **Better Approach Exists:** We can avoid duplicate combinations by skipping over repeated elements in recursion.

## **Optimized Approach (Alternative)**

A better approach would:

- **Use an iterative loop inside the recursive function** to prevent redundant calls.
- **Avoid using a **``**, saving space.**
- **Track used elements properly** to eliminate duplicates at the recursion level.

## **Conclusion**

This naive approach works but is inefficient. An optimized approach should handle duplicates **during recursion** instead of filtering them out later using `set`.

