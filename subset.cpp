#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sol;
        backtrack(nums, sol, ans, 0);
        return ans;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& sol, vector<vector<int>>& ans, int start) {
        ans.push_back(sol);

        for (int i = start; i < nums.size(); i++) {
            sol.push_back(nums[i]);
            backtrack(nums, sol, ans, i + 1);
            sol.pop_back();
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<vector<int>> result = solution.subsets(nums);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
