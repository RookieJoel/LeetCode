class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1] > prices[i]) totalProfit+=(prices[i+1]-prices[i]);
        }
        return totalProfit;

    }
};