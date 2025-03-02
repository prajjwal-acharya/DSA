#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i - 1]) continue;
            if(arr[i] > target) break; 
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

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
    
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    cout << "Combinations that sum to target (without duplicates): \n";
    for (auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
