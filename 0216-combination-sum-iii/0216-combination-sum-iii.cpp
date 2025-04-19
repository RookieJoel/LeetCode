class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> sub;
        vector<vector<int>> ans;
        solve(k,n,0,1,0,ans,sub);
        return ans;
    }

    void solve(int k,int target,int count,int curNum,int curSum,vector<vector<int>> &ans,vector<int> &sub){
        if(count == k){
            if(curSum == target) ans.push_back(sub);
            return;
        }
        if(curSum > target) return;
        for(int i=curNum;i<=9;i++){
            sub.push_back(i);
            solve(k,target,count+1,i+1,curSum+i,ans,sub);
            sub.pop_back();
        }
    }
};