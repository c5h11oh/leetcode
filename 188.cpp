#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.size() < 2) return 0;
        int rows = 2 * k - 1;
        int cols = prices.size();
        /*
        remain sells | holding stock | day
        2 | 0 | x (omit)
        1 | 1 | x (omit)
        1 | 0 | x
        0 | 1 | x
        0 | 0 | x
        
        row \ day | 0 | 1 | 2 | 3 | ...
        -------------------------------------------------------
        0(deleted)| V -- this row is all zero, can omit. --
        0(deleted)| V
        0         | X | V
        1         | X | X | V
        2         | X | X | X | V
        
        result: if (row <= col), that cell is impossible case (so fill in INT_MIN)
        */
        
        int dp[rows][cols];
        int cheapest = prices[0];
        for (int i = 0; i < rows; ++i)
            dp[i][0] = INT_MIN;
        
        for (int j = 1; j < cols; ++j) {
            dp[0][j] = max(dp[0][j-1], -cheapest + prices[j]);
            for (int i = 1; i < rows; ++i) {
                if ( j <= i )
                    dp[i][j] = INT_MIN;
                else if ( i & 1 ) { /* odd row: holding stock */
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] - prices[j]);
                }
                else { /* even: free of stock */
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + prices[j]);
                }
            }
            
            if (prices[j] < cheapest)
                cheapest = prices[j];
        }
        
        int result = INT_MIN;
        for (int i = 0; i < rows; ++i)
            if (dp[i][cols - 1] > result)
                result = dp[i][cols - 1];
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> in{2,1};
    cout << sol.maxProfit(1, in) << endl; 
}