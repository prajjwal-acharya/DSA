#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    void findCombinations(int ind, int target, vector<int> &arr, set<vector<int>> &ans, vector<int> &ds){
        if(ind == arr.size()){
            if(target == 0){
                ans.insert(ds);
            }
            return;
        }
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombinations(ind + 1, target - arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findCombinations(ind + 1, target, arr, ans, ds);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        set<vector<int>> ans;
        vector<int> ds;
        vector<vector<int>> answer;
        findCombinations(0, target, candidates, ans, ds);

        answer.assign(ans.begin(), ans.end());
        return answer;
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
