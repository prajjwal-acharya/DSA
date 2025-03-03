# Pivot Array - C++ Implementation

## Overview
This program rearranges an array (`nums`) based on a **pivot element**, ensuring:
1. Elements **smaller than `pivot`** appear first.
2. Elements **equal to `pivot`** appear next.
3. Elements **greater than `pivot`** appear last.

## Problem Statement
Given an array `nums` and an integer `pivot`, return a rearranged array where:
- All elements **less than `pivot`** appear before elements **equal to `pivot`**.
- All elements **equal to `pivot`** appear before elements **greater than `pivot`**.
- The **relative order** of elements is preserved.

## Approach
The approach follows these steps:
1. **Traverse the array three times**:
   - First, add elements **smaller than `pivot`**.
   - Then, add elements **equal to `pivot`**.
   - Finally, add elements **greater than `pivot`**.
2. **Preserve the relative order** within each category.

## Code Explanation

### **Class: `Solution`**
This class contains the method:
1. `pivotArray()`: Rearranges elements based on `pivot`.

### **Method: `pivotArray()`**
```cpp
vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> ds;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < pivot){
            ds.push_back(nums[i]);
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == pivot){
            ds.push_back(nums[i]);
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > pivot){
            ds.push_back(nums[i]);
        }
    }
    return ds;
}
```

### **Time & Space Complexity**
- **Time Complexity:** `O(n)`, since we traverse `nums` **three times**.
- **Space Complexity:** `O(n)`, as we use an extra array `ds`.

## **Optimized Approach**
Instead of three separate loops, we can optimize the approach using a **single loop**:
```cpp
vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> left, middle, right;
    for(int num : nums){
        if(num < pivot) left.push_back(num);
        else if(num == pivot) middle.push_back(num);
        else right.push_back(num);
    }
    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}
```
This improves efficiency by avoiding multiple passes over `nums`.

## **Conclusion**
This program efficiently rearranges an array around a pivot while preserving the relative order of elements.

