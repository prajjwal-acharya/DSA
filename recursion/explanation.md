# Combination Sum - C++ Implementation

## Overview
This program solves the **Combination Sum** problem using **Recursion and Backtracking**. It finds all unique combinations in a given list of numbers where the sum of the elements equals a given target. The same number can be used multiple times in a combination.

## Problem Statement
Given an array of **distinct integers** `candidates` and a target integer `target`, return **all unique combinations** where the sum of the chosen numbers equals `target`. The same number can be chosen **unlimited times**.

## Approach
The solution uses **Recursion and Backtracking** to explore all possible combinations:
1. Either include an element and reduce the target.
2. Or move to the next element without including it.
3. If `target == 0`, add the combination to the answer.

## Code Explanation

### **Class: `Solution`**
This class contains two methods:
1. `findCombinations()`: A recursive function that generates all valid combinations.
2. `combinationSum()`: Calls `findCombinations()` and returns the result.

### **Recursive Function: `findCombinations()`**
```cpp
void findCombinations(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
    if (ind == arr.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombinations(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back(); // Backtracking
    }
    findCombinations(ind + 1, target, arr, ans, ds);
}
```
- **Base Case:** If we reach the end of the array and `target == 0`, add the current combination (`ds`) to `ans`.
- **Include the element** (if it's not exceeding `target`), call the function again with the reduced `target`.
- **Backtrack:** Remove the last added element and move to the next index.

### **Function: `combinationSum()`**
```cpp
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(0, target, candidates, ans, ds);
    return ans;
}
```
This function initializes the answer list and calls the recursive function.

### **`main()` Function**
```cpp
int main() {
    Solution sol;
    int n, target;
    cout << "Enter number of elements in candidates: ";
    cin >> n;
    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    
    vector<vector<int>> result = sol.combinationSum(candidates, target);
    
    cout << "Combinations that sum to target: \n";
    for (auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
```
This function:
1. Takes input from the user.
2. Calls `combinationSum()`.
3. Prints all valid combinations.

## **Example Walkthrough**
### **Input**
```
Enter number of elements in candidates: 3
Enter the candidates: 2 3 6
Enter the target sum: 6
```
### **Recursive Calls Breakdown**
1. Include `2`: `{2, 2, 2}` ✅
2. Include `3`: `{3, 3}` ✅
3. Include `6`: `{6}` ✅

### **Output**
```
Combinations that sum to target:
[ 2 2 2 ]
[ 3 3 ]
[ 6 ]
```

## **Complexity Analysis**
- **Time Complexity:** `O(2^t * k)` where `t` is the target and `k` is the average length of combinations.
- **Space Complexity:** `O(k * x)`, where `x` is the total number of valid combinations.

## **Usage**
1. Clone the repository.
2. Compile the program using `g++`:
   ```sh
   g++ combination_sum.cpp -o combination_sum
   ```
3. Run the executable:
   ```sh
   ./combination_sum
   ```

## **Conclusion**
This program efficiently finds all combinations that sum to a target using recursion and backtracking. It is useful for solving **subset problems, knapsack variations, and decision-making problems**.

