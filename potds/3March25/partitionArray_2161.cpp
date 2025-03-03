#include "/Users/prajjwalacharya/Documents/coding/bits.h"
using namespace std;

class Solution {
public:
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
};

int main() {
    Solution sol;
    int n, pivot;
    cout << "Enter number of elements in nums: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of nums: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the pivot element: ";
    cin >> pivot;
    
    vector<int> result = sol.pivotArray(nums, pivot);

    cout << "Rearranged array: \n[ ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << "]\n";
    
    return 0;
}
