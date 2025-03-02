#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

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
			ds.pop_back();
		}
		findCombinations(ind + 1, target, arr, ans, ds);
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, target, candidates, ans, ds);
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
