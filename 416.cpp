#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int& i : nums)
            sum += i;
        if (sum % 2) return false; // the sum is an odd number
        
        bool dp[nums.size()][sum / 2];
        for (int j = 0; j < sum / 2; ++j) 
            dp[0][j] = false;
        dp[0][nums[0] - 1] = true;
        
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < sum / 2; ++j) {
                if (dp[i-1][j] || nums[i] == j + 1 || (j + 1 > nums[i] && dp[i-1][j-nums[i]]))
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[nums.size() - 1][sum / 2 - 1];
    }
};

int main() {
    Solution sol;
    vector<int> in{1, 5, 11, 5};
    cout << sol.canPartition(in) << endl;
}