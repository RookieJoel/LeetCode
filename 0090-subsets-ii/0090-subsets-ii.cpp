class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, sub, ans);
        return ans;
    }
    
private:
    void backtrack(int idx,
                   const vector<int>& nums,
                   vector<int>& sub,
                   vector<vector<int>>& ans) {
        ans.push_back(sub);
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) 
                continue;
            sub.push_back(nums[i]);
            backtrack(i + 1, nums, sub, ans);
            sub.pop_back();
        }
    }
};
